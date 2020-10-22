//
// Created by rezuki on 22/10/2020.
//

#include "shape.h"
#include "stroke.h"

void create_square(int sisi){
    int x0,y0;
    printf("Masukkan titik x awal (x0) : ");
    scanf("%d", &x0);
    printf("Masukkan titik y awal (y0) : ");
    scanf("%d", &y0);
    int x = x0+sisi;
    int y = y0+sisi;
    create_line(x0, x, y0, y0);
    create_line(x0, x0, y0, y);
    create_line(x0, x, y, y);
    create_line(x, x, y0, y);
}

void create_rectangle(int panjang, int lebar){
    int x0,y0;
    printf("Masukkan titik x awal (x0) : ");
    scanf("%d", &x0);
    printf("Masukkan titik y awal (y0) : ");
    scanf("%d", &y0);
    int x = x0+panjang;
    int y = y0+lebar;
    create_line(x0, x, y0, y0);
    create_line(x0, x0, y0, y);
    create_line(x0, x, y, y);
    create_line(x, x, y0, y);
}

void create_jajargenjang(int alas, int sisi_miring){
    int x0,y0;
    printf("Masukkan titik x awal (x0) : ");
    scanf("%d", &x0);
    printf("Masukkan titik y awal (y0) : ");
    scanf("%d", &y0);
    int x = x0+alas;
    int y = y0+sisi_miring;
    create_line(x0, x, y0, y0);//horizontal atas
    create_line(x0, x0-45, y0, y);//vertikal kiri
    create_line(x0-45, x-45, y, y);//horizontal bawah
    create_line(x, x-45, y0, y);//vertikal kanan
//    line(x0, y0, x, y0);//horizontal atas
//    line(x0, y0, x0-45, y);//vertikal kiri
//    line(x0-45, y, x-45, y);//horizontal bawah
//    line(x, y0, x-45, y);//vertikal kanan
}

void box_animated(){
    int i, j = 0;
    for( i = 0 ; i <= 320 ; i = i + 10, j++ )
    {
        rectangle(150,50+i,150+i,400);
        rectangle(250,150+i,200+i,400);
        setcolor(j);
        delay(100);

        if( i == 320 )
            break;
        if ( j == 15 )
            j = 2;
        cleardevice(); // clear screen
    }
}

void create_trapesium(int alas, int sisi_miring){
    int x0,y0;
    printf("Masukkan titik x awal (x0) : ");
    scanf("%d", &x0);
    printf("Masukkan titik y awal (y0) : ");
    scanf("%d", &y0);
    int x = x0+alas;
    int y = y0+sisi_miring;
    line(x0, y0, x, y0);//horizontal atas
    line(x0, y0, x0-45, y);//vertikal kiri
    line(x0-45, y, x+45, y);//horizontal bawah
    line(x, y0, x+45, y);//vertikal kanan
}

void create_belah_ketupat(int d1, int d2){
    int midX, midY;
    midX = getmaxx()/2;
    midY=getmaxy()/2;

    create_line(midX,abs(midY-d2),midX+d1,midY);
    create_line(midX+d1,midY, midX,midY+d2);
    create_line(midX,midY+d2, abs(midX-d1),midY);
    create_line(abs(midX-d1),midY,midX,abs(midY-d2));
}

void create_segitiga(int alas, int tinggi){
    int x0,y0;
    printf("Masukkan titik x awal (x0) : ");
    scanf("%d", &x0);
    printf("Masukkan titik y awal (y0) : ");
    scanf("%d", &y0);
    int x = x0+alas;
    int y = y0+tinggi;
//    line(x0, y0, x, y0);//horizontal atas
    line(x0, y0, x0, y);//vertikal kiri
    line(x0, y, x, y);//horizontal bawah
    line(x0, y0, x, y);//vertikal kanan
}