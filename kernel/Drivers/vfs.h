// vfs.h
#ifndef VFS_H
#define VFS_H

#include <stdint.h>
#include <stdbool.h>

#define VFS_MAX_FILES 10
#define VFS_MAX_FILE_NAME_LENGTH 32

typedef struct {
    char name[VFS_MAX_FILE_NAME_LENGTH];
    uint32_t start_block;
    uint32_t size;
} VFS_File;

void vfs_init();
bool vfs_mount();
void vfs_unmount();
bool vfs_create_file(const char* name);
bool vfs_write_file(const char* name, const uint8_t* data, uint32_t size);
bool vfs_read_file(const char* name, uint8_t* buffer, uint32_t size);

#endif // VFS_H
