//
// Created by rezuki on 22/10/2020.
//

#include "stroke.h"

#define SIN(x) sin(x * 3.141592653589 / 180)
#define COS(x) cos(x * 3.141592653589 / 180)

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

int * translate_point( int P[], int T[])
{
    P[0] = P[0] + T[0];
    P[1] = P[1] + T[1];

    return P;
}

int * translate_line( int P[][2], int T[])
{
    // calculating translated coordinates
    P[0][0] = P[0][0] + T[0];
    P[0][1] = P[0][1] + T[0];
    P[1][0] = P[1][0] + T[1];
    P[1][1] = P[1][1] + T[1];

    return P;
}

int * rotate_line(int P[][2], double angle) {
    int x_shifted = P[0][1] - P[0][0];
    int y_shifted = P[1][1] - P[1][0];

    P[0][1]=P[0][0]+(x_shifted * COS(angle) - y_shifted * SIN(angle));
    P[1][1]=P[1][0]+(x_shifted * SIN(angle) + y_shifted * COS(angle));

    return P;
}

//void findNewCoordinate(int s[][2], int p[][1])
//{
//    int temp[2][1] = { 0 };
//
//    for (int i = 0; i < 2; i++)
//        for (int j = 0; j < 1; j++)
//            for (int k = 0; k < 2; k++)
//                temp[i][j] += (s[i][k] * p[k][j]);
//
//    p[0][0] = temp[0][0];
//    p[1][0] = temp[1][0];
//}

// Scaling the Polygon
int * scale(int P[][2], int sx, int sy)
{
//    // Initializing the Scaling Matrix.
//    int s[2][2] = { sx, 0, 0, sy };
//    int p[2][1];

    P[0][1] = P[0][1] + (abs((P[0][1]-P[0][0]))*sx);
    P[1][1] = P[1][1] + (abs((P[1][1]-P[1][0]))*sy);


    return P;
}

int reflect(int x,  int y, int style, int measure)
{
    //horizontal
    if (style == 1){
        x = x - measure;
        return x;
    } else { //vertical
        y = y - measure;
        return y;
    }
}