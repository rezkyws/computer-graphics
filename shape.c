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

void create_square(int sisi, int x0, int y0) {
    int x = x0 + sisi;
    int y = y0 + sisi;
    create_line(x0, x, y0, y0);
    create_line(x0, x0, y0, y);
    create_line(x0, x, y, y);
    create_line(x, x, y0, y);
}

void create_rectangle(int panjang, int lebar, int x0, int y0) {
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
    int x0, y0;
    printf("Masukkan titik pusat x (x0) : ");
    scanf("%d", &x0);
    printf("Masukkan titik pusat y (y0) : ");
    scanf("%d", &y0);
//    midX = getmaxx() / 2;
//    midY = getmaxy() / 2;

    create_line(x0, x0 + d1, abs(y0 - d2), y0);
    create_line(x0 + d1, x0, y0, y0 + d2);
    create_line(x0, abs(x0 - d1), y0 + d2, y0);
    create_line(abs(x0 - d1), x0, y0, abs(y0 - d2));
}

void create_triangle(int alas, int tinggi, int x0, int y0) {
    int x = x0 + alas;
    int y = y0 + tinggi;

    create_line(x0, x0, y0, y);//left vertcal
    create_line(x0, x, y, y);//bottom horizontal
    create_line(x0, x, y0, y);//right vertical
    usleep(5 * 500);
}

void midpoint_algorithm(int x0, int y0, int radius, int width, int type) {
    float dx = 1, dy = 1;
    float x = radius - 1, y = 0;
    float error = dx - (radius << 1);
    if (type == 1) {
        for (; x >= y;) {
            putpixel(x0 + x, y0 + y, 1);
            putpixel(x0 + y, y0 + x, 2);
            putpixel(x0 - y, y0 + x, 3);
            putpixel(x0 - x, y0 + y, 4);
            putpixel(x0 - x, y0 - y, 5);
            putpixel(x0 - y, y0 - x, 6);
            putpixel(x0 + y, y0 - x, 7);
            putpixel(x0 + x, y0 - y, 8);
            if (width > 1) {
                for (int i = 1; i <= width; i++) {
                    putpixel(x0 + x - i, y0 + y - i, 1);
                    putpixel(x0 + y - i, y0 + x - i, 2);
                    putpixel(x0 - y + i, y0 + x - i, 3);
                    putpixel(x0 - x + i, y0 + y - i, 4);
                    putpixel(x0 - x + i, y0 - y + i, 5);
                    putpixel(x0 - y + i, y0 - x + i, 6);
                    putpixel(x0 + y - i, y0 - x + i, 7);
                    putpixel(x0 + x - i, y0 - y + i, 8);
                }
            }
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
    } else if (type == 2) {
        for (int i = 0; (x >= y); i++) {
            if (i % 9 < 6) {
                putpixel(x0 + x, y0 + y, 1);
                putpixel(x0 + y, y0 + x, 2);
                putpixel(x0 - y, y0 + x, 3);
                putpixel(x0 - x, y0 + y, 4);
                putpixel(x0 - x, y0 - y, 5);
                putpixel(x0 - y, y0 - x, 6);
                putpixel(x0 + y, y0 - x, 7);
                putpixel(x0 + x, y0 - y, 8);
                if (width > 1) {
                    for (int i = 1; i <= width; i++) {
                        putpixel(x0 + x - i, y0 + y - i, 1);
                        putpixel(x0 + y - i, y0 + x - i, 2);
                        putpixel(x0 - y + i, y0 + x - i, 3);
                        putpixel(x0 - x + i, y0 + y - i, 4);
                        putpixel(x0 - x + i, y0 - y + i, 5);
                        putpixel(x0 - y + i, y0 - x + i, 6);
                        putpixel(x0 + y - i, y0 - x + i, 7);
                        putpixel(x0 + x - i, y0 - y + i, 8);
                    }
                }
            }
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
    } else {
        for (int i = 0; (x >= y); i++) {
            if (i % 9 < 0.5) {
                putpixel(x0 + x, y0 + y, 1);
                putpixel(x0 + y, y0 + x, 2);
                putpixel(x0 - y, y0 + x, 3);
                putpixel(x0 - x, y0 + y, 4);
                putpixel(x0 - x, y0 - y, 5);
                putpixel(x0 - y, y0 - x, 6);
                putpixel(x0 + y, y0 - x, 7);
                putpixel(x0 + x, y0 - y, 8);
                if (width > 1) {
                    for (int i = 1; i <= width; i++) {
                        putpixel(x0 + x - i, y0 + y - i, 1);
                        putpixel(x0 + y - i, y0 + x - i, 2);
                        putpixel(x0 - y + i, y0 + x - i, 3);
                        putpixel(x0 - x + i, y0 + y - i, 4);
                        putpixel(x0 - x + i, y0 - y + i, 5);
                        putpixel(x0 - y + i, y0 - x + i, 6);
                        putpixel(x0 + y - i, y0 - x + i, 7);
                        putpixel(x0 + x - i, y0 - y + i, 8);
                    }
                }
            }

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
}

void create_smiley() {
    midpoint_algorithm(250, 250, 150, 1, 1);
    midpoint_algorithm(190, 230, 20, 1, 1);
    midpoint_algorithm(300, 230, 20, 1, 1);

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
    midpoint_algorithm(250, 250, 150, 1, 1);
    //rectangle bottom
    int x0, y0;
    x0 = 170;
    y0 = 290;
    int x = x0 + 125;
    int y = y0 + 30;
    dda_line_normal(x0, x, y0, y0, 2, 3);
    dda_line_normal(x0, x0, y0, y, 2, 3);
    dda_line_normal(x0, x, y, y, 2, 3);
    dda_line_normal(x, x, y0, y, 2, 3);
    //rectangle right
    x0 = 270;
    y0 = 320;
    x = x0 + 25;
    y = y0 - 120;
    dda_line_normal(x0, x, y0, y0, 2, 3);
    dda_line_normal(x0, x0, y0, y, 2, 3);
    dda_line_normal(x0, x, y, y, 2, 3);
    dda_line_normal(x, x, y0, y, 2, 3);
    //rectangle left
    x0 = 170;
    y0 = 320;
    x = x0 + 30;
    y = y0 - 120;
    dda_line_normal(x0, x, y0, y0, 1, 3);
    dda_line_normal(x0, x0, y0, y, 1, 3);
    dda_line_normal(x0, x, y, y, 1, 3);
    dda_line_normal(x, x, y0, y, 1, 3);
    //rectangle top
    x0 = 200;
    y0 = 170;
    x = x0 + 95;
    y = y0 + 30;
    dda_line_normal(x0, x, y0, y0, 14, 3);
    dda_line_normal(x0, x0, y0, y, 14, 3);
    dda_line_normal(x0, x, y, y, 14, 3);
    dda_line_normal(x, x, y0, y, 14, 3);
    //triangle top
    x0 = 200;
    y0 = 170;
    x = x0 - 30;
    y = y0 + 30;
    dda_line_normal(x0, x0, y0, y, 4, 3);//left vertcal
    dda_line_normal(x0, x, y, y, 4, 3);//bottom horizontal
    dda_line_normal(x0, x, y0, y, 4, 3);//right vertical
    usleep(5 * 500);
    //triangle
    x0 = 340;
    y0 = 200;
    x = x0 - 70;
    y = y0 + 100;
    dda_line_normal(x0, x0, y0, y, 2, 3);//right vertical
    dda_line_normal(x0, x, y, y - 50, 2, 2);//bottom horizontal
    dda_line_normal(x0, x, y0, y - 50, 2, 3);//top horizontal
    usleep(5 * 500);
}

void create_elipse(int rx, int ry, int xc, int yc){

    float dx, dy, d1, d2, x, y;
    x = 0;
    y = ry;

    // Initial decision parameter of region 1
    d1 = (ry * ry)
         - (rx * rx * ry)
         + (0.25 * rx * rx);
    dx = 2 * ry * ry * x;
    dy = 2 * rx * rx * y;

    // For region 1
    while (dx < dy) {

        // Print points based on 4-way symmetry
        putpixel(x + xc, y + yc,1);
        putpixel(-x + xc, y + yc,1);
        putpixel(x + xc, -y + yc,1);
        putpixel(-x + xc, -y + yc,1);

        // Checking and updating value of
        // decision parameter based on algorithm
        if (d1 < 0) {
            x++;
            dx = dx + (2 * ry * ry);
            d1 = d1 + dx + (ry * ry);
        }
        else {
            x++;
            y--;
            dx = dx + (2 * ry * ry);
            dy = dy - (2 * rx * rx);
            d1 = d1 + dx - dy + (ry * ry);
        }
    }

    // Decision parameter of region 2
    d2 = ((ry * ry) * ((x + 0.5) * (x + 0.5)))
         + ((rx * rx) * ((y - 1) * (y - 1)))
         - (rx * rx * ry * ry);

    // Plotting points of region 2
    while (y >= 0) {

        // printing points based on 4-way symmetry
        putpixel(x + xc, y + yc,1);
        putpixel(-x + xc, y + yc,1);
        putpixel(x + xc, -y + yc,1);
        putpixel(-x + xc, -y + yc,1);

        // Checking and updating parameter
        // value based on algorithm
        if (d2 > 0) {
            y--;
            dy = dy - (2 * rx * rx);
            d2 = d2 + (rx * rx) - dy;
        }
        else {
            y--;
            x++;
            dx = dx + (2 * ry * ry);
            dy = dy - (2 * rx * rx);
            d2 = d2 + dx - dy + (rx * rx);
        }
    }
}

void create_triangle_kaki(int alas, int tinggi, int P[][1])
{
    int x_centre, y_centre;
    y_centre = P[0][1] + tinggi;
    x_centre = alas/2;

//    create_line(P[0][0], P[0][0], P[0][1], y_centre);
    create_line(P[0][0]-x_centre,P[0][0]+x_centre, y_centre, y_centre);
//    create_line(P[0][0],, y_centre, y_centre);
    create_line(P[0][0],P[0][0]+x_centre, P[0][1], y_centre);
    create_line(P[0][0],P[0][0]-x_centre, P[0][1], y_centre);
}

void create_triangle_sisi(int sisi, int P[][2])
{

//    create_line(P[0][0], P[0][0], P[0][1], y_centre);
    create_line(P[0][0],P[0][1], P[1][0], P[1][1]);
    rotate_line(P,300);
    create_line(P[0][0],P[0][1], P[1][0], P[1][1]);
    int temp_x = P[0][1];// take the edge point of x
    int temp_y = P[1][1];// take the edge point of y
    rotate_line(P,60);//so in total it's 360, just like without rotate (back to normal)
    create_line(temp_x, P[0][1], temp_y, P[1][1]);
//    create_line(P[0][0],, y_centre, y_centre);
//    create_line(P[0][0],P[0][0]+x_centre, P[0][1], y_centre);
//    create_line(P[0][0],P[0][0]-x_centre, P[0][1], y_centre);
}

void create_belah_ketupat(int sisi, int P[][2])
{
    create_triangle_sisi(sisi,P);
    rotate_line(P,60);
    create_triangle_sisi(sisi,P);
//    create_line(P[0][0],P[0][1], P[1][0], P[1][1]);
//    int temp_x = P[0][1];
//    int temp_y = P[1][1];
//    rotate_line(P,300);
//    create_line(temp_x, P[0][1], temp_y, P[1][1]);
}

void scale_triangle(int P[][2],int sx,int sy)
{
    scale(P,0,sy);

//    create_line(P[0][0],P[0][1], P[1][0], P[1][1]);
//    int temp_x = P[0][1];
//    int temp_y = P[1][1];
//    rotate_line(P,300);
//    create_line(temp_x, P[0][1], temp_y, P[1][1]);
}

void create_layang(int sisi, int P[][2], int sy)
{
    int temp_x = P[0][1];
    create_triangle_sisi(sisi,P);
    rotate_line(P,60);
    scale(P,0,sy);
    create_line(P[0][0],P[0][1], P[1][0], P[1][1]);
    int temp_x2 = P[0][1];
    int temp_y = P[1][1];
    rotate_line(P,300);
//    scale(P,0,sy);
//    create_line(P[0][0],P[0][1], P[1][0], P[1][1]);
    // take the edge point of x
    // take the edge point of y
//    rotate_line(P,60);//so in total it's 360, just like without rotate (back to normal)
//    scale(P,0,sy);
    create_line(temp_x, temp_x2, P[1][0], temp_y);
//    create_line(P[0][0],P[0][1], P[1][0], P[1][1]);
//    int temp_x = P[0][1];
//    int temp_y = P[1][1];
//    rotate_line(P,300);
//    create_line(temp_x, P[0][1], temp_y, P[1][1]);
}

void create_trapesium(int alas, int tinggi, int x0, int y0)
{
    int alas_segitiga = alas/4;
    int sisi_square = alas / 2;
    create_triangle(-(alas_segitiga), tinggi, x0, y0);
    create_rectangle(sisi_square, tinggi,x0, y0);
    reflect(x0, y0, 1, alas_segitiga);
    create_triangle(alas_segitiga, tinggi, x0+sisi_square, y0);
}

void curve()
{
    for(float index = 0; index <= 5; index+=0.01)
    {
        float titik_awal_x = 250;
        float titik_awal_y = 250;
        float x_akhir = index;
        float y_akhir = (index*index);
        putpixel((titik_awal_x + x_akhir), (titik_awal_y - y_akhir), 3);
    }
}