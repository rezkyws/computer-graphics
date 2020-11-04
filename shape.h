//
// Created by rezuki on 22/10/2020.
//

#ifndef REZKY_SHAPE_H
#define REZKY_SHAPE_H

#include <graphics.h>

void create_line(int x0, int x, int y0, int y);
void create_square(int sisi);
void create_rectangle(int panjang, int lebar);
void create_rhombus(int alas, int sisi_miring);
void create_trapezium(int alas, int sisi_miring);
void create_triangle(int alas, int tinggi);
void create_diamond(int d1, int d2);
void box_animated();
void midpoint_algorithm(int x0, int y0, int radius);
void create_smiley();
void create_logo();

#endif //REZKY_SHAPE_H
