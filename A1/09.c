#include <stdio.h>

int main()
{
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%d\n", a + b);
    if (a + b >= 50)    
        printf("pass\n");
    else
        printf("fail\n");
    return 0;
}