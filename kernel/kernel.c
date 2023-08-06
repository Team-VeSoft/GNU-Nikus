// kernel.c - Главный файл операционной системы

#include <stdint.h>
#include <stdbool.h>
#include "keyboard.h" // Подключаем заголовочный файл для драйвера клавиатуры
#include "limine.h"   // Подключаем заголовочный файл для Limine

// Определение структуры памяти
struct MemoryRegion {
    uint64_t base;
    uint64_t size;
};

// Функция для инициализации системы
void init_system() {
    // Инициализация других компонентов системы
    // ...

    // Инициализация драйвера клавиатуры
    init_keyboard();
}

// Функция для обработки прерываний
void handle_interrupt() {
    // Обработка прерывания
}

// Функция для выделения памяти
void* allocate_memory(size_t size) {
    // Выделение памяти
    return NULL;
}

// Функция для освобождения памяти
void deallocate_memory(void* ptr) {
    // Освобождение памяти
}

// Определение точки входа для загрузчика Limine
void _start(struct MemoryRegion* mem_regions, size_t mem_region_count) {
    // Инициализация операционной системы
    init_system();

    // Вывод строки "Привет, мир!"
    const char* message = "Hello World!\n";
    for (int i = 0; message[i] != '\0'; ++i) {
        putc(message[i]);
    }

    // Выход из ядра и передача управления загрузчику Limine
    limine_reboot();
}
