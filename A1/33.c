#include <stdio.h>

int main()
{
    int n, ans = 0;
    scanf("%d", &n);
    for (int i = 0;i < n;i++){
        char ch;
        getchar(); // '\n'
        scanf("%c", &ch);
        // printf("c = %c\n", ch);
        if (ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')
            ans++;
    }
    printf("%d\n", ans);
    return 0;
}