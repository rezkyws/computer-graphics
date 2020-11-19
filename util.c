//
// Created by rezuki on 22/10/2020.
//
#include <graphics.h>
#include "util.h"
#include "shape.h"
#include "stroke.h"


void make_window(int x, int y) {
    initwindow(x, y, "Rezky Canvas");
}

void main_menu() {
    int ch;
    do {
        // prompt user input
        printf("******** MENU ********\n");
        printf("1. Garis\n");
        printf("2. Kotak\n");
        printf("3. Persegi Panjang\n");
        printf("4. Jajar Genjang\n");
        printf("5. Trapesium\n");
        printf("6. Segitiga\n");
        printf("7. Belah Ketupat\n");
        printf("8. Eksplorasi\n");
        printf("9. Lingkaran\n");
        printf("10. Smiley\n");
        printf("11. Logo\n");
        printf("12. Translation point\n");
        printf("13. Translation line\n");
        printf("14. Rotate line\n");
        printf("15. Scalling line\n");
        printf("16. Elipse\n");
        printf("17. Segitiga sama kaki\n");
        printf("18. Segitiga sama sisi\n");
        printf("19. Belah ketupat (transformation)\n");
        printf("20. Layang layang (transformation)\n");
        printf("21. Trapesium (transformation)\n");
        printf("22. Fungsi kuadrat translate\n");
        printf("23. Exit\n");

        printf("\nSilahkan pilih menu?\n");

        scanf("%d", &ch);

        switch (ch) {
            case 1: {
                int x0, y0, x, y;
                printf("Masukkan titik x awal (x0) : ");
                scanf("%d", &x0);
                printf("Masukkan titik y awal (y0) : ");
                scanf("%d", &y0);
                printf("Masukkan titik x akhir (x) : ");
                scanf("%d", &x);
                printf("Masukkan titik y akhir (y) : ");
                scanf("%d", &y);
                create_line(x0, x, y0, y);
            }
                break;
            case 2: {
                int sisi;
                int x0, y0;
                printf("Masukkan titik x awal (x0) : ");
                scanf("%d", &x0);
                printf("Masukkan titik y awal (y0) : ");
                scanf("%d", &y0);
                printf("Masukkan nilai sisi : ");
                scanf("%d", &sisi);
                create_square(sisi,x0,y0);
            }
                break;
            case 3: {
                int panjang, lebar;
                printf("Masukkan nilai panjang : ");
                scanf("%d", &panjang);
                printf("Masukkan nilai lebar : ");
                scanf("%d", &lebar);
                int x0, y0;
                printf("Masukkan titik x awal (x0) : ");
                scanf("%d", &x0);
                printf("Masukkan titik y awal (y0) : ");
                scanf("%d", &y0);
                create_rectangle(panjang, lebar, x0, y0);
            }
                break;
            case 4: {
                int alas, sisi_miring;
                printf("Masukkan nilai alas : ");
                scanf("%d", &alas);
                printf("Masukkan nilai sisi miring : ");
                scanf("%d", &sisi_miring);
                create_rhombus(alas, sisi_miring);
            }
                break;
            case 5: {
                int alas, sisi_miring;
                printf("Masukkan nilai alas : ");
                scanf("%d", &alas);
                printf("Masukkan nilai sisi miring : ");
                scanf("%d", &sisi_miring);
                create_trapezium(alas, sisi_miring);
            }
                break;
            case 6: {
                int alas, tinggi, x0, y0;
                printf("Masukkan nilai alas : ");
                scanf("%d", &alas);
                printf("Masukkan nilai tinggi : ");
                scanf("%d", &tinggi);
                printf("Masukkan titik awal x : ");
                scanf("%d", &x0);
                printf("Masukkan titik awal y : ");
                scanf("%d", &y0);

                create_triangle(alas, tinggi, x0, y0);
            }
                break;
            case 7: {
                int d1, d2;
                printf("Masukkan panajang diagonal horizontal : ");
                scanf("%d", &d1);
                printf("Masukkan panjang diagonal vertikal : ");
                scanf("%d", &d2);
                create_diamond(d1, d2);
            }
                break;
            case 8: {
                box_animated();
            }
                break;
            case 9: {
                int x0, y0, radius, width, type;
                printf("Masukkan titik x0 : ");
                scanf("%d", &x0);
                printf("Masukkan titik y0 : ");
                scanf("%d", &y0);
                printf("Masukkan panjang radius : ");
                scanf("%d", &radius);
                printf("Masukkan tebal : ");
                scanf("%d", &width);
                printf("Masukkan tipe garis (1. normal 2. dash 3. dot : ");
                scanf("%d", &type);
                midpoint_algorithm(x0, y0, radius, width, type);
            }
                break;
            case 10: {
                create_smiley();
            }
                break;
            case 11: {
                create_logo();
            }
                break;
            case 12: {
                int x0,y0,tx,ty;
                printf("Masukkan titik awal x : ");
                scanf("%d", &x0);
                printf("Masukkan titik awal y : ");
                scanf("%d", &y0);
                printf("Masukkan besar translasi x : ");
                scanf("%d", &tx);
                printf("Masukkan besar translasi y : ");
                scanf("%d", &ty);
                int P[2]; // coordinates of point
                P[0] = x0;
                P[1] = y0;
                int T[] = {tx, ty}; // translation factor
                putpixel(P[0],P[1],1);
                translate_point(P, T);
                putpixel(P[0],P[1],1);
            }
                break;
            case 13: {
                int x0,y0,x1,y1,tx,ty;
                printf("Masukkan titik awal x : ");
                scanf("%d", &x0);
                printf("Masukkan titik awal y : ");
                scanf("%d", &y0);
                printf("Masukkan titik akhir x : ");
                scanf("%d", &x1);
                printf("Masukkan titik akhir y : ");
                scanf("%d", &y1);
                printf("Masukkan besar translasi x : ");
                scanf("%d", &tx);
                printf("Masukkan besar translasi y : ");
                scanf("%d", &ty);
                int P[2][2]; // coordinates of point

                P[0][0] = x0;
                P[0][1] = x1;
                P[1][0] = y0;
                P[1][1] = y1;

                create_line(P[0][0], P[0][1], P[1][0], P[1][1]);

                int T[] = {tx, ty}; // translation factor
                translate_line(P, T);

                create_line(P[0][0], P[0][1], P[1][0], P[1][1]);
            }
                break;
            case 14: {
                int x0,y0,x1,y1;
                printf("Masukkan titik awal x : ");
                scanf("%d", &x0);
                printf("Masukkan titik awal y : ");
                scanf("%d", &y0);
                printf("Masukkan titik akhir x : ");
                scanf("%d", &x1);
                printf("Masukkan titik akhir y : ");
                scanf("%d", &y1);
                int P[2][2]; // coordinates of point

                P[0][0] = x0;
                P[0][1] = x1;
                P[1][0] = y0;
                P[1][1] = y1;

                create_line(P[0][0], P[0][1], P[1][0], P[1][1]);

                double angle;
                printf("Enter the angle for rotation:");
                scanf("%lf", &angle);

                rotate_line(P,angle);

                create_line(P[0][0], P[0][1], P[1][0], P[1][1]);
            }
                break;
            case 15: {
//                int x0,y0,x1,y1,sx,sy;
//                printf("Masukkan titik awal x : ");
//                scanf("%d", &x0);
//                printf("Masukkan titik awal y : ");
//                scanf("%d", &y0);
//                printf("Masukkan titik akhir x : ");
//                scanf("%d", &x1);
//                printf("Masukkan titik akhir y : ");
//                scanf("%d", &y1);

//                int x[] = { 100, 200, 300 };
//                int y[] = { 200, 100, 200 };
//                int sx = 2, sy = 2;
//
//                scale_triangle(x, y, sx,sy);
//
//                int P[2][2]; // coordinates of point
//
//                P[0][0] = x0;
//                P[0][1] = x1;
//                P[1][0] = y0;
//                P[1][1] = y1;
//
//                create_line(P[0][0], P[0][1], P[1][0], P[1][1]);
//
//                printf("Masukkan besar scalling x : ");
//                scanf("%d", &sx);
//                printf("Masukkan besar scalling y : ");
//                scanf("%d", &sy);
//
//                scale_triangle(P,sx,sy);
//
//                create_line(P[0][0], P[0][1], P[1][0], P[1][1]);
            }
                break;
            case 16: {
                int rx,ry,xc,yc;
                printf("Masukkan titik center x : ");
                scanf("%d", &xc);
                printf("Masukkan titik center y : ");
                scanf("%d", &yc);
                printf("Masukkan titik radius x : ");
                scanf("%d", &rx);
                printf("Masukkan titik radius y : ");
                scanf("%d", &ry);

                create_elipse(rx, ry, xc, yc);
            }
                break;
            case 17: {
                int alas,tinggi,P[0][1];
                printf("Masukkan titik awal x : ");
                scanf("%d", &P[0][0]);
                printf("Masukkan titik awal y : ");
                scanf("%d", &P[0][1]);
                printf("Masukkan panjang alas ");
                scanf("%d", &alas);
                printf("Masukkan tinggi : ");
                scanf("%d", &tinggi);

                create_triangle_kaki(alas,tinggi,P);
            }
                break;
            case 18: {
                int sisi,P[2][2];
                printf("Masukkan titik awal x : ");
                scanf("%d", &P[0][0]);
                printf("Masukkan titik awal y : ");
                scanf("%d", &P[1][0]);
                printf("Masukkan panjang sisi ");
                scanf("%d", &sisi);


                P[0][1] = P[0][0]+sisi;
                P[1][1] = P[1][0];


                create_triangle_sisi(sisi,P);
            }
                break;
            case 19: {
                int sisi,P[2][2];
                printf("Masukkan titik awal x : ");
                scanf("%d", &P[0][0]);
                printf("Masukkan titik awal y : ");
                scanf("%d", &P[1][0]);
                printf("Masukkan panjang sisi ");
                scanf("%d", &sisi);


                P[0][1] = P[0][0]+sisi;
                P[1][1] = P[1][0];


                create_belah_ketupat(sisi,P);
            }
                break;
            case 20: {
                int sisi,P[2][2];
                int sy = 2;
                printf("Masukkan titik awal x : ");
                scanf("%d", &P[0][0]);
                printf("Masukkan titik awal y : ");
                scanf("%d", &P[1][0]);
                printf("Masukkan panjang sisi ");
                scanf("%d", &sisi);

                P[0][1] = P[0][0]+sisi;
                P[1][1] = P[1][0];

                create_layang(sisi, P, sy);
            }
                break;
            case 21: {
                int alas, tinggi, x0, y0;
                printf("Masukkan nilai alas : ");
                scanf("%d", &alas);
                printf("Masukkan nilai tinggi : ");
                scanf("%d", &tinggi);
                printf("Masukkan titik awal x : ");
                scanf("%d", &x0);
                printf("Masukkan titik awal y : ");
                scanf("%d", &y0);
                create_trapesium(alas, tinggi, x0, y0);
            }
            case 22: {
                void curve();
            }
        }
    } while (ch != 23);
    exit(1);
}