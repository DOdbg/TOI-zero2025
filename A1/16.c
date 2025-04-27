#include <stdio.h>

int main()
{
    char c[10];
    scanf("%s", c);
    if (c[2] == '1' && c[3] == '6')
        printf("yes\n");
    else
        printf("no\n");
    return 0;
}