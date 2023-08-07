// vga.c - Драйвер VGA

#include <stdint.h>
#include "vga.h"

// Адрес видеобуфера графического режима
volatile uint32_t* vga_buffer = (uint32_t*)0xA0000;

// Функция для инициализации драйвера VGA
void init_vga() {
    // а где
}

// Функция для вывода пикселя на экран
void putpixel_vga(int x, int y, uint32_t color) {
    int index = y * VGA_WIDTH + x;
    vga_buffer[index] = color;
}
