#include <stdio.h>
#include<graphics.h>
#include "util.h"

int main() {
    int x,y;
    printf("Masukkan size canvas :\n");
    printf("Panjang : ");
    scanf("%d",&x);
    printf("Lebar : ");
    scanf("%d", &y);
    make_window(x,y);
    main_menu();

    getch();

    return 0;
}



