#include <stdio.h>

int main()
{
    char c[2], op;
    scanf("%s %c", c, &op);
    int a = 10 * (c[0] - '0') + (c[1] - '0'), b = 10 * (c[1] - '0') + (c[0] - '0');
    printf("%d %c %d = ", a, op, b);
    int ans = 0;
    if (op == '+')
        ans = a + b;
    else if (op == '*')
        ans = a * b;
    printf("%d\n", ans);
    return 0;
}