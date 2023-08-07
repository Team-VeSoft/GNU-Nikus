// vga.h - Заголовочный файл для драйвера VGA

#ifndef VGA_H
#define VGA_H

#include <stdint.h>

// Функция для инициализации драйвера VGA
void init_vga();

// Функция для вывода пикселя на экран
void putpixel_vga(int x, int y, uint32_t color);

#endif // VGA_H
