// commands.c - Файл с обработчиками команд

#include "commands.h"
#include "vga.h" // Подключаем драйвер VGA

// Обработчик команды "help"
void command_help() {
    // Выводим список доступных команд
    const char* help_message = "Available commands:\n"
                               "help - Display this help message\n"
                               "hello - Print \"Hello, VGA!\"\n";
    for (int i = 0; help_message[i] != '\0'; ++i) {
        putc_vga(help_message[i]);
    }
}

// Обработчик команды "hello"
void command_hello() {
    const char* hello_message = "Hello, VGA!\n";
    for (int i = 0; hello_message[i] != '\0'; ++i) {
        putc_vga(hello_message[i]);
    }
}

// Функция для обработки команд
void handle_command(const char* command) {
    // Используем оператор switch для обработки команд
    switch (command[0]) {
        case 'h':
            if (strcmp(command, "help") == 0) {
                command_help();
            }
            break;
        case 'a':
            if (strcmp(command, "hello") == 0) {
                command_hello();
            }
            break;
    }
    
    // Если команда не найдена, выводим сообщение об ошибке
    const char* error_message = "Unknown command. Type 'help' for a list of commands.\n";
    for (int i = 0; error_message[i] != '\0'; ++i) {
        putc_vga(error_message[i]);
    }
}
