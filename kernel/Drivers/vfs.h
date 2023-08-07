// vfs.h - Заголовочный файл для расширенной виртуальной файловой системы

#ifndef VFS_H
#define VFS_H

#include <stdint.h>
#include <stdbool.h>

#define VFS_MAX_FILES 10
#define VFS_MAX_FILE_SIZE 256

typedef struct {
    char name[32];
    uint32_t start_block; // Физический блок на носителе
    uint32_t size;
} VFS_File;

// Инициализация виртуальной файловой системы
void vfs_init();

// Подключение носителя (монтирование)
bool vfs_mount();

// Отключение носителя (демонтирование)
void vfs_unmount();

// Создание файла
bool vfs_create_file(const char* name);

// Запись данных в файл
bool vfs_write_file(const char* name, const uint8_t* data, uint32_t size);

// Чтение данных из файла
bool vfs_read_file(const char* name, uint8_t* buffer, uint32_t size);

#endif // VFS_H
