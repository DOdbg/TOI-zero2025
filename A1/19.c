#include <stdio.h>

int main()
{
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    if (a == b && b == c)
        printf("all the same\n");
    else if (a != b && a != c && b != c)
        printf("all different\n");
    else
        printf("neither\n");
    return 0;
}