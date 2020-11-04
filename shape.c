//
// Created by rezuki on 22/10/2020.
//

#include "shape.h"
#include "stroke.h"

void create_line(int x0, int x, int y0, int y) {
    int warna, tipe_garis, width;
    printf("Masukkan tipe garis (1. Biasa 2. Dashed 3. Dotted 4. Dashed-dotted) : ");
    scanf("%d", &tipe_garis);
    printf("Masukkan warna (dalam angka) : ");
    scanf("%d", &warna);
    printf("Masukkan tebal garis (default 1) : ");
    scanf("%d", &width);
    if (tipe_garis == 1) {
        dda_line_normal(x0, x, y0, y, warna, width);
    } else if (tipe_garis == 2) {
        dda_line_dashed(x0, x, y0, y, warna, width);
    } else if (tipe_garis == 3) {
        dda_line_dotted(x0, x, y0, y, warna, width);
    } else {
        dda_line_dashed_dotted(x0, x, y0, y, warna, width);
    }
}

void create_square(int sisi) {
    int x0, y0;
    printf("Masukkan titik x awal (x0) : ");
    scanf("%d", &x0);
    printf("Masukkan titik y awal (y0) : ");
    scanf("%d", &y0);
    int x = x0 + sisi;
    int y = y0 + sisi;
    create_line(x0, x, y0, y0);
    create_line(x0, x0, y0, y);
    create_line(x0, x, y, y);
    create_line(x, x, y0, y);
}

void create_rectangle(int panjang, int lebar) {
    int x0, y0;
    printf("Masukkan titik x awal (x0) : ");
    scanf("%d", &x0);
    printf("Masukkan titik y awal (y0) : ");
    scanf("%d", &y0);
    int x = x0 + panjang;
    int y = y0 + lebar;
    create_line(x0, x, y0, y0);
    create_line(x0, x0, y0, y);
    create_line(x0, x, y, y);
    create_line(x, x, y0, y);
}

void create_rhombus(int alas, int sisi_miring) {
    int x0, y0;
    printf("Masukkan titik x awal (x0) : ");
    scanf("%d", &x0);
    printf("Masukkan titik y awal (y0) : ");
    scanf("%d", &y0);
    int x = x0 + alas;
    int y = y0 + sisi_miring;
    create_line(x0, x, y0, y0);//top horizontal
    create_line(x0, x0 - 45, y0, y);//left vertical
    create_line(x0 - 45, x - 45, y, y);//bottom horizontal
    create_line(x, x - 45, y0, y);//right vertical
}

void box_animated() {
    int x0, y0, sisi, x, y;
    x0 = 1;
    y0 = 1;
    sisi = 50;
    for (int i = 0; i < 20; i++) {
        x = x0 + sisi;
        y = y0 + sisi;
        dda_line_normal(x0, x, y0, y0, 1, 1);
        dda_line_normal(x0, x0, y0, y, 2, 1);
        dda_line_normal(x0, x, y, y, 3, 1);
        dda_line_normal(x, x, y0, y, 4, 1);
        sisi = sisi + 10;
    }
    sisi = 50;
    x0 = 252;
    y0 = 1;
    for (int i = 0; i < 20; i++) {
        x = x0 + sisi;
        y = y0 + sisi;
        dda_line_normal(x0, x, y0, y0, 1, 1);
        dda_line_normal(x0, x0, y0, y, 2, 1);
        dda_line_normal(x0, x, y, y, 3, 1);
        dda_line_normal(x, x, y0, y, 4, 1);
        sisi = sisi + 10;
    }
    sisi = 50;
    x0 = 1;
    y0 = 251;
    for (int i = 0; i < 20; i++) {
        x = x0 + sisi;
        y = y0 + sisi;
        dda_line_normal(x0, x, y0, y0, 1, 1);
        dda_line_normal(x0, x0, y0, y, 2, 1);
        dda_line_normal(x0, x, y, y, 3, 1);
        dda_line_normal(x, x, y0, y, 4, 1);
        sisi = sisi + 10;
    }
    sisi = 50;
    x0 = 251;
    y0 = 251;
    for (int i = 0; i < 20; i++) {
        x = x0 + sisi;
        y = y0 + sisi;
        dda_line_normal(x0, x, y0, y0, 1, 1);
        dda_line_normal(x0, x0, y0, y, 2, 1);
        dda_line_normal(x0, x, y, y, 3, 1);
        dda_line_normal(x, x, y0, y, 4, 1);
        sisi = sisi + 10;
    }
}

void create_trapezium(int alas, int sisi_miring) {
    int x0, y0;
    printf("Masukkan titik x awal (x0) : ");
    scanf("%d", &x0);
    printf("Masukkan titik y awal (y0) : ");
    scanf("%d", &y0);
    int x = x0 + alas;
    int y = y0 + sisi_miring;

    create_line(x0, x, y0, y0);//top horizontal
    create_line(x0, x0 - 45, y0, y);//left vertical
    create_line(x0 - 45, x + 45, y, y);//bottom horizontal
    create_line(x, x + 45, y0, y);//right vertical
}

void create_diamond(int d1, int d2) {
    int midX, midY;
    midX = getmaxx() / 2;
    midY = getmaxy() / 2;

    create_line(midX, abs(midY - d2), midX + d1, midY);
    create_line(midX + d1, midY, midX, midY + d2);
    create_line(midX, midY + d2, abs(midX - d1), midY);
    create_line(abs(midX - d1), midY, midX, abs(midY - d2));
}

void create_triangle(int alas, int tinggi) {
    int x0, y0;
    printf("Masukkan titik x awal (x0) : ");
    scanf("%d", &x0);
    printf("Masukkan titik y awal (y0) : ");
    scanf("%d", &y0);
    int x = x0 + alas;
    int y = y0 + tinggi;

    create_line(x0, x0, y0, y);//left vertcal
    create_line(x0, x, y, y);//bottom horizontal
    create_line(x0, x, y0, y);//right vertical
    usleep(5 * 500);
}

void midpoint_algorithm(int x0, int y0, int radius) {
    float dx = 1, dy = 1;
    float x = radius - 1, y = 0;
    float error = dx - (radius << 1);
    for (; x >= y;) {
        putpixel(x0 + x, y0 + y, 1);
        putpixel(x0 + y, y0 + x, 2);
        putpixel(x0 - y, y0 + x, 3);
        putpixel(x0 - x, y0 + y, 4);
        putpixel(x0 - x, y0 - y, 5);
        putpixel(x0 - y, y0 - x, 6);
        putpixel(x0 + y, y0 - x, 7);
        putpixel(x0 + x, y0 - y, 8);
        if (error > 0) {
            x = x - 1;
            dx = dx + 2;
            error = error + (-radius << 1) + dx;
        }
        if (error <= 0) {
            y = y + 1;
            error = error + dy;
            dy = dy + 2;
        }
    }
}

void create_smiley() {
    midpoint_algorithm(250,250,150);
    midpoint_algorithm(190,230,20);
    midpoint_algorithm(300,230,20);

    int x0, y0, radius;
    x0 = 250;
    y0 = 270;
    radius = 50;
    float dx = 1, dy = 1;
    float x = radius - 1, y = 0;
    float error = dx - (radius << 1);
    for (; x >= y;) {
        putpixel(x0 + x, y0 + y, 1);
        putpixel(x0 + y, y0 + x, 2);
        putpixel(x0 - y, y0 + x, 3);
        putpixel(x0 - x, y0 + y, 4);
        if (error > 0) {
            x = x - 1;
            dx = dx + 2;
            error = error + (-radius << 1) + dx;
        }
        if (error <= 0) {
            y = y + 1;
            error = error + dy;
            dy = dy + 2;
        }
    }
}

void create_logo() {
    midpoint_algorithm(250,250,150);
    //rectangle bottom
    int x0, y0;
    x0 = 170;
    y0 = 290;
    int x = x0 + 125;
    int y = y0 + 30;
    dda_line_normal(x0, x, y0, y0,2,3);
    dda_line_normal(x0, x0, y0, y,2,3);
    dda_line_normal(x0, x, y, y,2,3);
    dda_line_normal(x, x, y0, y,2,3);
    //rectangle right
    x0 = 270;
    y0 = 320;
    x = x0 + 25;
    y = y0 - 120;
    dda_line_normal(x0, x, y0, y0,2,3);
    dda_line_normal(x0, x0, y0, y,2,3);
    dda_line_normal(x0, x, y, y,2,3);
    dda_line_normal(x, x, y0, y,2,3);
    //rectangle left
    x0 = 170;
    y0 = 320;
    x = x0 + 30;
    y = y0 - 120;
    dda_line_normal(x0, x, y0, y0,1,3);
    dda_line_normal(x0, x0, y0, y,1,3);
    dda_line_normal(x0, x, y, y,1,3);
    dda_line_normal(x, x, y0, y,1,3);
    //rectangle top
    x0 = 200;
    y0 = 170;
    x = x0 + 95;
    y = y0 + 30;
    dda_line_normal(x0, x, y0, y0,14,3);
    dda_line_normal(x0, x0, y0, y,14,3);
    dda_line_normal(x0, x, y, y,14,3);
    dda_line_normal(x, x, y0, y,14,3);
    //triangle top
    x0 = 200;
    y0 = 170;
    x = x0 - 30;
    y = y0 + 30;
    dda_line_normal(x0, x0, y0, y,4,3);//left vertcal
    dda_line_normal(x0, x, y, y,4,3);//bottom horizontal
    dda_line_normal(x0, x, y0, y,4,3);//right vertical
    usleep(5 * 500);
    //triangle
    x0 = 340;
    y0 = 200;
    x = x0 - 70;
    y = y0 + 100;
    dda_line_normal(x0, x0, y0, y,2,3);//right vertical
    dda_line_normal(x0, x, y, y-50,2,2);//bottom horizontal
    dda_line_normal(x0, x, y0, y-50,2,3);//top horizontal
    usleep(5 * 500);
}