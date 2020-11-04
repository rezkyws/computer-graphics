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

#endif //REZKY_STROKE_H
