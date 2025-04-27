#include <stdio.h>

int main()
{
    int a, b;
    scanf("%d %d", &a, &b);

    if (a <= 1990){
        if (b <= 1500)
            printf("1250\n");
        else if (b <= 2000)
            printf("1400\n");
        else
            printf("2000\n");
    }
    else if (a <= 1999){
        if (b <= 1500)
            printf("1100\n");
        else if (b <= 2000)
            printf("1300\n");
        else
            printf("1700\n");
    }
    else {
        if (b <= 1500)
            printf("1000\n");
        else if (b <= 2000)
            printf("1200\n");
        else
            printf("1500\n");
    }

    return 0;
}