#include <stdio.h>

int min(int a, int b){
    if (a < b)
        return a;
    return b;
}

int main()
{
    int n, ans = 1e9;
    scanf("%d", &n);
    for (int i = 0;i < n;i++){
        int a;
        scanf("%d", &a);
        ans = min(ans, a);
    }
    printf("%d\n", ans);
    return 0;
}