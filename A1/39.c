#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    long long ans = 1ll;
    for (int i = 2;i <= n;i++)
        ans *= (i + 0ll);
    printf("%lld\n", ans);
    return 0;
}