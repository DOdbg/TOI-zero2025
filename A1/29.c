#include <stdio.h>

int main()
{
    char c[10];
    scanf("%s", c);
    int ans = 0;
    for (int i = 0;i < 3;i++)
        if (c[i] == 'a' || c[i] == 'e' || c[i] == 'i' || c[i] == 'o' || c[i] == 'u')
            ans++;
    printf("%d\n", ans);
    return 0;
}