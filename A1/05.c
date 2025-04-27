#include <stdio.h>

int main()
{
    int a, b;
    char ans[4][50] = {"winter", "spring", "summer", "fall"};
    scanf("%d %d", &a, &b);
    printf("%s\n", ans[((a - 1) / 3) + (a % 3 == 0 && b >= 21)]);

    return 0;
}