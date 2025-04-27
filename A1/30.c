#include <stdio.h>

int max(int a, int b){
    if (a > b)
        return a;
    return b;
}

int main()
{
    int n;
    scanf("%d", &n);
    if (n == 1){
        int a, b;
        scanf("%d %d", &a, &b);
        printf("%d\n", max(a, b));
        return 0;
    }

    int sum = 0;
    for (int i = 0;i < n;i++){
        int a, b;
        scanf("%d %d", &a, &b);
        printf("%d %c ", max(a, b), "+="[i == n - 1]);
        sum += max(a, b);
    }
    printf("%d\n", sum);
    return 0;
}