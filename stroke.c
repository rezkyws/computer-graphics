//
// Created by rezuki on 22/10/2020.
//

#include "stroke.h"


void dda_line_normal(int x1, int x2, int y1, int y2, int colour, int width) {
    float dx, dy, len, x, y;
    int i;

    dx = abs(x2 - x1);
    dy = abs(y2 - y1);

    if (dx >= dy)
        len = dx;
    else
        len = dy;

    dx = (x2 - x1) / len;
    dy = (y2 - y1) / len;

    x = x1;
    y = y1;
    for (i = 0; i <= len; i++) {
        if (width > 1) {
            for (float j = 0; j < width; j += 0.1) {
                //vertical line
                if (x1 == x2) {
//                    putpixel(x + j, y, colour);
                    putpixel(x - j, y, colour);
                }
                    //horizontal line
                else if (y1 == y2) {
//                    putpixel(x, y + j, colour); //INSIDE
                    putpixel(x, y - j, colour); //OUTSIDE
                }
                    //m!=0 line
                else if (x1 < x2) {
//                    putpixel(x + j, y - j, colour);
                    putpixel(x - j, y + j, colour);
                } else {
//                    putpixel(x - j, y - j, colour);
                    putpixel(x - j, y + j, colour);
                }
            }
        } else {
            putpixel(x, y, colour);
        }
        x += dx;
        y += dy;
        usleep(5 * 500);
    }
}

void dda_line_dashed(int x1, int x2, int y1, int y2, int colour, int width) {
    float dx, dy, len, x, y;
    int i;
    dx = abs(x2 - x1);
    dy = abs(y2 - y1);
    if (dx >= dy)
        len = dx;
    else
        len = dy;

    dx = (x2 - x1) / len;
    dy = (y2 - y1) / len;
    x = x1;
    y = y1;

    for (i = 0; i <= len; i++) {
        if (i % 9 < 6) {
            putpixel(x, y, colour);
            if (width > 1) {
                for (float j = 0; j < width; j += 0.1) {
                    //vertical line
                    if (x1 == x2) {
//                    putpixel(x + j, y, colour);
                        putpixel(x - j, y, colour);
                    }
                        //horizontal line
                    else if (y1 == y2) {
//                    putpixel(x, y + j, colour); //INSIDE
                        putpixel(x, y - j, colour); //OUTSIDE
                    }
                        //m!=0 line
                    else if (x1 < x2) {
//                    putpixel(x + j, y - j, colour);
                        putpixel(x - j, y + j, colour);
                    } else {
//                    putpixel(x - j, y - j, colour);
                        putpixel(x - j, y + j, colour);
                    }
                }
            }
        }
        x += dx;
        y += dy;
        usleep(5 * 500);
    }
}

void dda_line_dotted(int x1, int x2, int y1, int y2, int colour, int width) {
    float dx, dy, len, x, y;
    int i;
    dx = abs(x2 - x1);
    dy = abs(y2 - y1);
    if (dx >= dy)
        len = dx;
    else
        len = dy;

    dx = (x2 - x1) / len;
    dy = (y2 - y1) / len;
    x = x1;
    y = y1;

    for (i = 0; i <= len; i++) {
        if (i % 9 == 0) {
            putpixel(x, y, colour);
            if (width > 1) {
                for (float j = 0; j < width; j += 0.1) {
                    //vertical line
                    if (x1 == x2) {
//                    putpixel(x + j, y, colour);
                        putpixel(x - j, y, colour);
                    }
                        //horizontal line
                    else if (y1 == y2) {
//                    putpixel(x, y + j, colour); //INSIDE
                        putpixel(x, y - j, colour); //OUTSIDE
                    }
                        //m!=0 line
                    else if (x1 < x2) {
//                    putpixel(x + j, y - j, colour);
                        putpixel(x - j, y + j, colour);
                    } else {
//                    putpixel(x - j, y - j, colour);
                        putpixel(x - j, y + j, colour);
                    }
                }
            }
        }
        x += dx;
        y += dy;
        usleep(5 * 500);
    }
}

void dda_line_dashed_dotted(int x1, int x2, int y1, int y2, int colour, int width) {
    float dx, dy, len, x, y;
    int i;
    dx = abs(x2 - x1);
    dy = abs(y2 - y1);
    if (dx >= dy)
        len = dx;
    else
        len = dy;

    dx = (x2 - x1) / len;
    dy = (y2 - y1) / len;
    x = x1;
    y = y1;
    putpixel(x1, y1, colour);
    for (i = 0; i <= len; i++) {
        // dashed line
        if (i % 9 < 1) {}
        else if (i % 9 < 6) {
            putpixel(x, y, colour);
            if (width > 1) {
                for (float j = 0; j < width; j += 0.1) {
                    //vertical line
                    if (x1 == x2) {
//                    putpixel(x + j, y, colour);
                        putpixel(x - j, y, colour);
                    }
                        //horizontal line
                    else if (y1 == y2) {
//                    putpixel(x, y + j, colour); //INSIDE
                        putpixel(x, y - j, colour); //OUTSIDE
                    }
                        //m!=0 line
                    else if (x1 < x2) {
//                    putpixel(x + j, y - j, colour);
                        putpixel(x - j, y + j, colour);
                    } else {
//                    putpixel(x - j, y - j, colour);
                        putpixel(x - j, y + j, colour);
                    }
                }
            }
        } else if (i % 9 == 7) {} // space
        // dot
        else {
            putpixel(x, y, colour);
            if (width > 1) {
                for (float j = 0; j < width; j += 0.1) {
                    //vertical line
                    if (x1 == x2) {
//                    putpixel(x + j, y, colour);
                        putpixel(x - j, y, colour);
                    }
                        //horizontal line
                    else if (y1 == y2) {
//                    putpixel(x, y + j, colour); //INSIDE
                        putpixel(x, y - j, colour); //OUTSIDE
                    }
                        //m!=0 line
                    else if (x1 < x2) {
//                    putpixel(x + j, y - j, colour);
                        putpixel(x - j, y + j, colour);
                    } else {
//                    putpixel(x - j, y - j, colour);
                        putpixel(x - j, y + j, colour);
                    }
                }
            }
        }
        x += dx;
        y += dy;
    }
}

void bresenham_line(int x0, int y0, int x1, int y1, int colour, int width) {
    int dx, dy, p, x, y;

    dx = x1 - x0;
    dy = y1 - y0;

    x = x0;
    y = y0;

    putpixel(x0, y0, colour);
    putpixel(x1, y1, colour);

    p = 2 * dy - dx;
    int batas_y = y + width;
    int batas_x = x + width;

    while (x < x1) {
        if (p >= 0) {
            putpixel(x, y, colour);
            for (int increament = 0; y + increament <= batas_y; increament++) {
                putpixel(x - increament, y + increament, colour);
            }
            for (int increament = 0; x + increament <= batas_x; increament++) {
                putpixel(x + increament, y - increament, colour);
            }
            y = y + 1;
            p = p + 2 * dy - 2 * dx;
        } else {
            putpixel(x, y, colour);
            p = p + 2 * dy;
        }
        for (int increament = 0; y + increament <= batas_y; increament++) {
            putpixel(x - increament, y + increament, colour);
        }
        for (int increament = 0; x + increament <= batas_x; increament++) {
            putpixel(x + increament, y - increament, colour);
        }
        x = x + 1;
        batas_y = y + width;
        batas_x = x + width;
    }
}