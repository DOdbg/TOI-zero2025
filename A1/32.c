#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0;i < 3 && n - 2 * i >= 1;i++){
        for (int j = 0;j < n - 2 * i;j++)
            printf("*");
        printf("\n");
    }    
    return 0;
}