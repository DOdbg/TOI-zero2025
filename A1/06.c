#include <stdio.h>

int main()
{
    int a, b;
    scanf("%d %d", &a, &b);
    if (a % b)
        printf("no\n");
    else
        printf("yes\n");
    return 0;
}