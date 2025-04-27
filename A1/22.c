#include <stdio.h>

int main()
{
    int month, n;
    scanf("%d %d", &n, &month);
    if ((month == 12 && n >= 22) || (month == 1 && n <= 19)) 
        printf("capricorn\n");
    if ((month == 1 && n >= 20) || (month == 2 && n <= 18)) 
        printf("aquarius\n");
    if ((month == 2 && n >= 19) || (month == 3 && n <= 20))
        printf("pisces\n");
    if ((month == 3 && n >= 21) || (month == 4 && n <= 19)) 
        printf("aries\n");
    if ((month == 4 && n >= 20) || (month == 5 && n <= 20)) 
        printf("taurus\n");
    if ((month == 5 && n >= 21) || (month == 6 && n <= 21))
        printf("gemini\n");
    if ((month == 6 && n >= 22) || (month == 7 && n <= 22)) 
        printf("cancer\n");
    if ((month == 7 && n >= 23) || (month == 8 && n <= 22)) 
        printf("leo\n");
    if ((month == 8 && n >= 23) || (month == 9 && n <= 22)) 
        printf("virgo\n");
    if ((month == 9 && n >= 23) || (month == 10 && n <= 23)) 
        printf("libra\n");
    if ((month == 10 && n >= 24) || (month == 11 && n <= 21)) 
        printf("scorpio\n");
    if ((month == 11 && n >= 22) || (month == 12 && n <= 21)) 
        printf("sagittarius\n");
    return 0;
}