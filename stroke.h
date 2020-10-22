//
// Created by rezuki on 22/10/2020.
//

#ifndef REZKY_STROKE_H
#define REZKY_STROKE_H

//#include <iostream>
#include <graphics.h>

void create_line(int x0, int x, int y0, int y);
void dda_algorithm(int x1, int x2, int y1, int y2, int colour, int width);
void bresenham_algorithm(int x0, int y0, int x1, int y1, int colour, int width);
void dda_line_dashed_dotted(int x1, int x2, int y1, int y2, int colour, int width);
void dda_line_dashed(int x1, int x2, int y1, int y2, int colour, int width);
void dda_line_dotted(int x1, int x2, int y1, int y2, int colour, int width);
void DDA(int x1, int x2, int y1, int y2, int colour, int width);
void draw_line(int x1, int x2, int y1, int y2, int colour, int width);

#endif //REZKY_STROKE_H
