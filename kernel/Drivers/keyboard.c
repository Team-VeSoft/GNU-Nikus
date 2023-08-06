// keyboard.c - Драйвер клавиатуры

#include <stdint.h>
#include <stdbool.h>
#include "keyboard.h"

// Порт для чтения данных из порта клавиатуры
#define KEYBOARD_DATA_PORT 0x60

// Переменная для хранения состояния драйвера клавиатуры
static bool keyboard_initialized = false;

// Функция для инициализации драйвера клавиатуры
void init_keyboard() {
    // Выполняем инициализацию только один раз
    if (!keyboard_initialized) {
        // Здесь выполняется необходимая инициализация

        // Устанавливаем флаг инициализации
        keyboard_initialized = true;
    }
}

// Функция для чтения символа с клавиатуры
char read_key() {
    char keycode;

    // Ждем, пока клавиша будет нажата
    while (true) {
        // Читаем код клавиши
        keycode = inb(KEYBOARD_DATA_PORT);

        // Проверяем, если клавиша нажата
        if (keycode != 0) {
            return keycode;
        }
    }
}

// Основная функция драйвера клавиатуры
void keyboard_main() {
    init_keyboard();

    while (true) {
        // Читаем символ с клавиатуры
        char keycode = read_key();

        // Обрабатываем символ (например, выводим его на экран)
        char ascii = key_to_ascii(keycode);
        if (ascii != '\0') {
            // Ваша обработка символа, например, вывод на экран
            putc(ascii); // Предполагается, что у вас есть функция putc для вывода символов
        }
    }
}

// Функция для преобразования кода клавиши в ASCII символ
char key_to_ascii(char keycode) {
    // Пример преобразования: простое соответствие кодов клавиш ASCII символам
    // Для реальной ОС потребуется более сложная таблица соответствия
    switch (keycode) {
        case 0x1E: return 'a';
        case 0x30: return 'b';
        // Добавьте соответствия для других клавиш
        default: return '\0';
    }
}
