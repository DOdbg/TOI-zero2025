#include <stdio.h>

int main()
{
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    if (a >= 5 && b >= 20 && c >= 25)
        printf("pass\n");
    else
        printf("fail\n");
    return 0;
}