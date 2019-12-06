#pragma once
typedef enum _COLOR
{
    COLOR_GREEN,
    COLOR_RED
} COLOR;

void init_color();

void deinit_color();

void print_color(COLOR color, char* message);
