//
// Created by rezuki on 22/10/2020.
//
#include<graphics.h>
#include "util.h"
#include "shape.h"
#include "stroke.h"



void make_window(int x, int y){
    initwindow(x,y,"Rezky Canvas");
}

void main_menu(){
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
        printf("9. Exit\n");

        printf("\nSilahkan pilih menu?\n");

        scanf("%d", &ch);

        switch (ch) {
            case 1: {
                int x0,y0,x,y;
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
                printf("Masukkan nilai sisi : ");
                scanf("%d", &sisi);
                create_square(sisi);
            }

                break;

            case 3: {
                int panjang, lebar;
                printf("Masukkan nilai panjang : ");
                scanf("%d", &panjang);
                printf("Masukkan nilai lebar : ");
                scanf("%d", &lebar);
                create_rectangle(panjang, lebar);
            }

                break;

            case 4: {
                int alas, sisi_miring;
                printf("Masukkan nilai alas : ");
                scanf("%d", &alas);
                printf("Masukkan nilai sisi miring : ");
                scanf("%d", &sisi_miring);
                create_jajargenjang(alas, sisi_miring);
            }
                break;
            case 5: {
                int alas, sisi_miring;
                printf("Masukkan nilai alas : ");
                scanf("%d", &alas);
                printf("Masukkan nilai sisi miring : ");
                scanf("%d", &sisi_miring);
                create_trapesium(alas, sisi_miring);
            }
                break;
            case 6: {
                int alas, tinggi;
                printf("Masukkan nilai alas : ");
                scanf("%d", &alas);
                printf("Masukkan nilai tinggi : ");
                scanf("%d", &tinggi);
                create_segitiga(alas, tinggi);
            }
                break;
            case 7: {
                int d1, d2;
                printf("Masukkan koordinat titik tengah diagonal (x) : ");
                scanf("%d", &d1);
                printf("Masukkan koordinat titik tengah diagonal (y) : ");
                scanf("%d", &d2);
                create_belah_ketupat(d1, d2);
            }
                break;
            case 8: {
                box_animated();
            }
        }

    } while (ch != 9);
}