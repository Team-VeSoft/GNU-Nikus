// keyboard.h - Заголовочный файл для драйвера клавиатуры

#ifndef KEYBOARD_H
#define KEYBOARD_H

// Определение функций
void init_keyboard();
char read_key();
void keyboard_main();
char key_to_ascii(char keycode);

#endif // KEYBOARD_H
