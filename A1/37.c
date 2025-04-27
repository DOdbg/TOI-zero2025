#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    while (n >= 1000){
        printf("M");
        n -= 1000;
    }
    if (n >= 900){
        printf("CM");
        n -= 900;
    }
    while (n >= 500){
        printf("D");
        n -= 500;
    }
    if (n >= 400){
        printf("CD");
        n -= 400;
    }
    while (n >= 100){
        printf("C");
        n -= 100;
    }
    if (n >= 90){
        printf("XC");
        n -= 90;
    }
    while (n >= 50){
        printf("L");
        n -= 50;
    }
    if (n >= 40){
        printf("XL");
        n -= 10;
    }
    while (n >= 10){
        printf("X");
        n -= 10;
    }
    if (n >= 9){
        printf("IX");
        n -= 9;
    }
    while (n >= 5){
        printf("V");
        n -= 5;
    }
    if (n >= 4){
        printf("IV");
        n -= 4;
    }
    while (n >= 1){
        printf("I");
        n -= 1;
    }
    return 0;
}