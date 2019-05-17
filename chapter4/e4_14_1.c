#include<stdio.h>

#define swap(t,x,y) { t tmp = x; x = y; y = tmp;}

main(){

    int a = 5, b= 10;
    swap(int, a, b);
    printf("a %d b %d \n", a,b);

}
