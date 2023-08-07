// commands.c - Файл с обработчиками команд

#include "commands.h"
#include "vga.h" // Подключаем драйвер VGA
#include "vfs.h" // Подключаем виртуальную файловую систему

// Обработчик команды "help"
void command_help() {
    // Выводим список доступных команд
    const char* help_message = "Available commands:\n"
                               "help - Display this help message\n"
                               "hello - Print \"Hello, VGA!\"\n"
                               "mkdir <name> - Create a directory\n"
                               "rm <name> - Remove a file or directory\n"
                               "ls - List files\n"
                               "cfile <name> - Create a file\n"
                               "efile <name> - Edit a file\n";
    for (int i = 0; help_message[i] != '\0'; ++i) {
        putc_vga(help_message[i]);
    }
}

// Обработчик команды "mkdir"
void command_mkdir(const char* name) {
    if (vfs_create_directory(name)) {
        const char* message = "Directory created.\n";
        for (int i = 0; message[i] != '\0'; ++i) {
            putc_vga(message[i]);
        }
    } else {
        const char* message = "Failed to create directory.\n";
        for (int i = 0; message[i] != '\0'; ++i) {
            putc_vga(message[i]);
        }
    }
}

// Обработчик команды "rm"
void command_rm(const char* name) {
    if (vfs_remove(name)) {
        const char* message = "File or directory removed.\n";
        for (int i = 0; message[i] != '\0'; ++i) {
            putc_vga(message[i]);
        }
    } else {
        const char* message = "Failed to remove file or directory.\n";
        for (int i = 0; message[i] != '\0'; ++i) {
            putc_vga(message[i]);
        }
    }
}

// Обработчик команды "ls"
void command_ls() {
    // Вывод списка файлов
    // ...
}

// Обработчик команды "cfile"
void command_cfile(const char* name) {
    if (vfs_create_file(name)) {
        const char* message = "File created.\n";
        for (int i = 0; message[i] != '\0'; ++i) {
            putc_vga(message[i]);
        }
    } else {
        const char* message = "Failed to create file.\n";
        for (int i = 0; message[i] != '\0'; ++i) {
            putc_vga(message[i]);
        }
    }
}

// Обработчик команды "efile"
void command_efile(const char* name) {
    // Редактирование файла
    // ...
}

// Функция для обработки команд
void handle_command(const char* command) {
    // Разделение строки команды на аргументы
    // ...

    // Используем оператор switch для обработки команд
    switch (args_count) {
        case 1:
            if (strcmp(command, "help") == 0) {
                command_help();
            } else if (strcmp(command, "ls") == 0) {
                command_ls();
            }
            break;
        case 2:
            if (strcmp(command, "mkdir") == 0) {
                command_mkdir(args[1]);
            } else if (strcmp(command, "rm") == 0) {
                command_rm(args[1]);
            } else if (strcmp(command, "cfile") == 0) {
                command_cfile(args[1]);
            } else if (strcmp(command, "efile") == 0) {
                command_efile(args[1]);
            }
            break;
        default:
            // Если команда не найдена, выводим сообщение об ошибке
            const char* error_message = "Unknown command. Type 'help' for a list of commands.\n";
            for (int i = 0; error_message[i] != '\0'; ++i) {
                putc_vga(error_message[i]);
            }
            break;
    }
}
