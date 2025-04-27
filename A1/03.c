#include <stdio.h>

int max(int a, int b){
    if (a > b)
        return a;
    return b;
}

int main()
{
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    printf("%d\n", max(a, max(b, c)));
    return 0;
}