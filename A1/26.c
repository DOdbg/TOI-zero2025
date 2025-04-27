#include <stdio.h>

int main()
{
    int a[2] = {0, 0};
    for (int i = 0;i < 3;i++){
        int t;
        scanf("%d", &t);
        a[t % 2]++;
    }
    printf("even %d\nodd %d\n", a[0], a[1]);
    return 0;
}