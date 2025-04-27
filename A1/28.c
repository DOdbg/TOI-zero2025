#include <stdio.h>

int main()
{
    char c[10];
    scanf("%s", c);
    for (int i = 3;i >= 0;i--)
        printf("%c", c[i]);
    return 0;
}