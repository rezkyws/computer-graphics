//
// Created by rezuki on 22/10/2020.
//

#include "stroke.h"

void create_line(int x0, int x, int y0, int y) {
    int warna, tipe_garis, width;
    printf("Masukkan tipe garis (1. Biasa 2. Dashed 3. Dotted 4. Dashed-dotted) : ");
    scanf("%d", &tipe_garis);
    /**
     * 1. Biru
     */
    printf("Masukkan warna (dalam angka) : ");
    scanf("%d", &warna);
    printf("Masukkan tebal garis (default 1) : ");
    scanf("%d", &width);
    if (tipe_garis == 1) {
//        DDA(x0, x, y0, y, warna, width);
        draw_line(x0, x, y0, y, warna, width);
    } else if (tipe_garis == 2) {
        dda_line_dashed(x0, x, y0, y, warna, width);
    } else if (tipe_garis == 3) {
        dda_line_dotted(x0, x, y0, y, warna, width);
    } else {
        dda_line_dashed_dotted(x0, x, y0, y, warna, width);
    };
};


//void DDA(int x1, int x2, int y1, int y2, int colour, int width)
//{
////    int x,y;
//    // calculate dx & dy
//    int dx = x2 - x1;
//    int dy = y2 - y1;
//
//    // calculate steps required for generating pixels
//    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
//
//    // calculate increment in x & y for each steps
//    float Xinc = dx / (float) steps;
//    float Yinc = dy / (float) steps;
//
//
//
//    // Put pixel for each step
//    float X = x1;
//    float Y = y1;
//
//    int batas_y = Y + width;
//    int batas_x = X + width;
//    for (int i = 0; i <= steps; i++)
//    {
//        putpixel (X,Y,colour);  // put pixel at (X,Y)
//        for (int increament = 0; Y + increament < batas_y; increament++) {
////                putpixel(x+increament,y-increament,colour);
//            if (x1 == x2)
//                putpixel(X + increament, Y, colour);
//            else if (y1 == y2)
//                putpixel(X, Y + increament, colour);
//            else
//                putpixel(X - increament, Y + increament, colour);
//
//        }
//        for (int increament = 0; X + increament < batas_x; increament++) {
//            if (x1 == x2)
//                putpixel(X - increament, Y, colour);
//            else if (y1 == y2)
//                putpixel(X, Y - increament, colour);
//            else
//                putpixel(X + increament, Y - increament, colour);
////                putpixel(x-increament,y+increament,colour);
//        }
//        X += Xinc;           // increment in x at each step
//        Y += Yinc;           // increment in y at each step
//        batas_y = Y + width;
//        batas_x = X + width;
////        delay(100);          // for visualization of line-
//        // generation step by step
//    }
//}

void draw_line(int x1, int x2, int y1, int y2, int colour, int width) {
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

    x = x1 + 0.1;
    y = y1 + 0.1;
    for (i = 0; i <= len; i++) {
        if (width > 1) {
            for (float j = 0; j < width; j += 0.1) {
                if (x1 == x2) {
                        putpixel(x + j, y, colour);
                        putpixel(x - j, y, colour);
                } else if (y1 == y2) {
                        putpixel(x, y + j, colour); //INSIDE
                        putpixel(x, y - j, colour); //OUTSIDE
                } else {
                        putpixel(x + j, y - j, colour);
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

void dda_algorithm(int x1, int x2, int y1, int y2, int colour, int width) {
    int x, y, dx, dy, step, i;
    dx = abs(x2 - x1);
    dy = abs(y2 - y1);

    if (dx >= dy)
        step = dx;
    else
        step = dy;

    dx = (x2 - x1) / step;
    dy = (y2 - y1) / step;

    x = x1;
    y = y1;

    int batas_y = y + width;
    int batas_x = x + width;

    i = 1;

    while (i <= step) {
        putpixel(x, y, colour);
        for (int increament = 0; y + increament < batas_y; increament++) {
//                putpixel(x+increament,y-increament,colour);
            if (x1 == x2)
                putpixel(x + increament, y, colour);
            else if (y1 == y2)
                putpixel(x, y + increament, colour);
            else
                putpixel(x - increament, y + increament, colour);

        }
        for (int increament = 0; x + increament < batas_x; increament++) {
            if (x1 == x2)
                putpixel(x - increament, y, colour);
            else if (y1 == y2)
                putpixel(x, y - increament, colour);
            else
                putpixel(x + increament, y - increament, colour);
//                putpixel(x-increament,y+increament,colour);
        }
        x = x + dx;
        y = y + dy;
        i = i + 1;
        batas_y = y + width;
        batas_x = x + width;
//        delay(100);
    }
}

void bresenham_algorithm(int x0, int y0, int x1, int y1, int colour, int width) {
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
//                putpixel(x+increament,y-increament,colour);
                putpixel(x - increament, y + increament, colour);
            }
            for (int increament = 0; x + increament <= batas_x; increament++) {
                putpixel(x + increament, y - increament, colour);
//                putpixel(x-increament,y+increament,colour);
            }
            y = y + 1;
            p = p + 2 * dy - 2 * dx;
        } else {
            putpixel(x, y, colour);
            p = p + 2 * dy;
        }
        for (int increament = 0; y + increament <= batas_y; increament++) {
//                putpixel(x+increament,y-increament,colour);
            putpixel(x - increament, y + increament, colour);
        }
        for (int increament = 0; x + increament <= batas_x; increament++) {
            putpixel(x + increament, y - increament, colour);
//                putpixel(x-increament,y+increament,colour);
        }
        x = x + 1;
        batas_y = y + width;
        batas_x = x + width;
    }
}

void dda_line_dashed_dotted(int x1, int x2, int y1, int y2, int colour, int width) {
    float dx, dy, len, x, y, xi, yi;
    int i;
    dx = abs(x2 - x1);
    dy = abs(y2 - y1);
    if (dx >= dy)
        len = dx;
    else
        len = dy;

    dx = (x2 - x1) / len;
    dy = (y2 - y1) / len;
    x = x1 + 0.5;
    y = y1 + 0.5;
    int batas_y = y + width;
    int batas_x = x + width;
//    putpixel(x1,y1,colour);
//    putpixel(x2,y2,colour);
    for (i = 0; i <= len; i++) {
        if (i % 9 < 2) {}
        else if (i % 9 < 6) {
            putpixel(x, y, colour);
            for (int increament = 0; y + increament < batas_y; increament++) {
//                putpixel(x+increament,y-increament,colour);
                if (x1 == x2)
                    putpixel(x + increament, y, colour);
                else if (y1 == y2)
                    putpixel(x, y + increament, colour);
                else
                    putpixel(x - increament, y + increament, colour);

            }
            for (int increament = 0; x + increament < batas_x; increament++) {
                if (x1 == x2)
                    putpixel(x - increament, y, colour);
                else if (y1 == y2)
                    putpixel(x, y - increament, colour);
                else
                    putpixel(x + increament, y - increament, colour);
//                putpixel(x-increament,y+increament,colour);
            }
            batas_y = y + width;
            batas_x = x + width;
        } else if (i % 9 == 7) {}
        else
            putpixel(x, y, colour);
        x += dx;
        y += dy;
    }

}

void dda_line_dashed(int x1, int x2, int y1, int y2, int colour, int width) {
    float dx, dy, len, x, y, xi, yi;
    int i;
    dx = abs(x2 - x1);
    dy = abs(y2 - y1);
    if (dx >= dy)
        len = dx;
    else
        len = dy;

    dx = (x2 - x1) / len;
    dy = (y2 - y1) / len;
    x = x1 + 0.5;
    y = y1 + 0.5;

//    putpixel(x1,y1,3);
//    putpixel(x2,y2,3);
    int batas_y = y + width;
    int batas_x = x + width;

    for (i = 0; i <= len; i++) {
        if (i % 9 < 2) {}
        else if (i % 9 < 6) {
            putpixel(x, y, colour);
            for (int increament = 0; y + increament < batas_y; increament++) {
//                putpixel(x+increament,y-increament,colour);
                if (x1 == x2)
                    putpixel(x + increament, y, colour);
                else if (y1 == y2)
                    putpixel(x, y + increament, colour);
                else
                    putpixel(x - increament, y + increament, colour);

            }
            for (int increament = 0; x + increament < batas_x; increament++) {
                if (x1 == x2)
                    putpixel(x - increament, y, colour);
                else if (y1 == y2)
                    putpixel(x, y - increament, colour);
                else
                    putpixel(x + increament, y - increament, colour);
            }
        } else if (i % 9 == 7) {}
        else {}
        x += dx;
        y += dy;
        batas_y = y + width;
        batas_x = x + width;
    }

}

void dda_line_dotted(int x1, int x2, int y1, int y2, int colour, int width) {
    float dx, dy, len, x, y, xi, yi;
    int i;
    dx = abs(x2 - x1);
    dy = abs(y2 - y1);
    if (dx >= dy)
        len = dx;
    else
        len = dy;

    dx = (x2 - x1) / len;
    dy = (y2 - y1) / len;
    x = x1 + 0.5;
    y = y1 + 0.5;

    int batas_y = y + width;
    int batas_x = x + width;

//    putpixel(x1,y1,3);
//    putpixel(x2,y2,3);

    for (i = 0; i <= len; i++) {
        if (i % 9 < 1) {
            putpixel(x, y, colour);
            for (int increament = 0; y + increament < batas_y; increament++) {
//                putpixel(x+increament,y-increament,colour);
                if (x1 == x2)
                    putpixel(x + increament, y, colour);
                else if (y1 == y2)
                    putpixel(x, y + increament, colour);
                else
                    putpixel(x - increament, y + increament, colour);

            }
            for (int increament = 0; x + increament < batas_x; increament++) {
                if (x1 == x2)
                    putpixel(x - increament, y, colour);
                else if (y1 == y2)
                    putpixel(x, y - increament, colour);
                else
                    putpixel(x + increament, y - increament, colour);
//                putpixel(x-increament,y+increament,colour);
            }
        }
        x += dx;
        y += dy;
        batas_y = y + width;
        batas_x = x + width;
    }

}