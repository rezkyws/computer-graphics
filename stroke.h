//
// Created by rezuki on 22/10/2020.
//

#ifndef REZKY_STROKE_H
#define REZKY_STROKE_H

#include <graphics.h>

void dda_line_dashed_dotted(int x1, int x2, int y1, int y2, int colour, int width);
void dda_line_dashed(int x1, int x2, int y1, int y2, int colour, int width);
void dda_line_dotted(int x1, int x2, int y1, int y2, int colour, int width);
void dda_line_normal(int x1, int x2, int y1, int y2, int colour, int width);
int * translate_point ( int P[], int T[]);
int * translate_line ( int P[][2], int T[]);
int * rotate_line(int P[][2], double angle);
int * scale(int P[][2], int sx, int sy);
int reflect(int x,  int y, int style, int measure);

#endif //REZKY_STROKE_H
