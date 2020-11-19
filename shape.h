//
// Created by rezuki on 22/10/2020.
//

#ifndef REZKY_SHAPE_H
#define REZKY_SHAPE_H

#include <graphics.h>

void create_line(int x0, int x, int y0, int y);
void create_square(int sisi, int x0, int y0);
void create_rectangle(int panjang, int lebar, int x0, int y0);
void create_rhombus(int alas, int sisi_miring);
void create_trapezium(int alas, int sisi_miring);
void create_triangle(int alas, int tinggi, int x0, int y0);
void create_diamond(int d1, int d2);
void box_animated();
void midpoint_algorithm(int x0, int y0, int radius, int width, int type);
void create_smiley();
void create_logo();
void create_elipse(int rx, int ry, int xc, int yc);
void create_triangle_kaki(int alas, int tinggi, int P[][1]);
void create_triangle_sisi(int sisi, int P[][2]);
void create_belah_ketupat(int sisi, int P[][2]);
void create_layang(int sisi, int P[][2], int sy);
void scale_triangle(int P[][2],int sx,int sy);
void create_trapesium(int alas, int tinggi, int x0, int y0);
void curve();

#endif //REZKY_SHAPE_H
