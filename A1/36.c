#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    n -= n % 10;
    while (n >= 0){
        printf("%d ", n);
        n -= 10;
    }
    return 0;
}