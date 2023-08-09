// keyboard.c
#include <stdbool.h>
#include "keyboard.h"
#include "vga.h" // Подключаем драйвер VGA

#define KEYBOARD_DATA_PORT 0x60

static bool keyboard_initialized = false;

// Добавляем таблицу преобразования кодов клавиш в символы ASCII
static char keymap[] = {
    '\0', '\0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '-', '=', '\b', '\t',
    'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', '[', ']', '\n', '\0',
    'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', ';', '\'', '`', '\0', '\\',
    'z', 'x', 'c', 'v', 'b', 'n', 'm', ',', '.', '/', '\0', '*', '\0',
    ' ', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0',
    '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0',
    '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0',
    '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0'
};

void init_keyboard() {
    if (!keyboard_initialized) {
        // Здесь можно выполнять необходимую инициализацию

        keyboard_initialized = true;
    }
}

char read_key() {
    char keycode;
    while (true) {
        keycode = inb(KEYBOARD_DATA_PORT);
        if (keycode != 0) {
            return keycode;
        }
    }
}

void keyboard_main() {
    init_keyboard();

    while (true) {
        char keycode = read_key();
        char ascii = key_to_ascii(keycode);
        if (ascii != '\0') {
            putc_vga(ascii);
        }
    }
}

char key_to_ascii(char keycode) {
    if (keycode < sizeof(keymap)) {
        return keymap[keycode];
    }
    return '\0';
}
