#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    if (n > 9 || n == 0){
        printf("Error : Out of range\n");
        return 0;
    }
    if (n < 1){
        printf("Error : Please input positive number\n");
        return 0;
    }
    if (n == 1)
        printf("I");
    else if (n == 2)
        printf("II");
    else if (n == 3)
        printf("III");
    else if (n == 4)
        printf("IV");
    else if (n == 5)
        printf("V");
    else if (n == 6)
        printf("VI");
    else if (n == 7)
        printf("VII");
    else if (n == 8)
        printf("VIII");
    else if (n == 9)
        printf("IX");
    return 0;
}