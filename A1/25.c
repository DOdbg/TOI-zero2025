#include <stdio.h>
#include <string.h>

int main()
{
    char c[10];
    scanf("%s", c);
    int n = strlen(c);
    char back = c[n - 1];
    if (c[0] == 'Q' || c[0] == 'q')
        printf("queen");
    else if (c[0] == 'J' || c[0] == 'j')
        printf("jack");
    else if (c[0] == 'A' || c[0] == 'a')
        printf("ace");
    else if (c[0] == 'K' || c[0] == 'k')
        printf("king");
    else
        for (int i = 0;i < n - 1;i++)
            printf("%c", c[i]);
    printf(" of ");
    if (back == 'D' || back == 'd')
        printf("diamonds\n");
    else if (back == 'H' || back == 'h')
        printf("hearts\n");
    else if (back == 'S' || back == 's')
        printf("spades\n");
    else
        printf("clubs\n");
    return 0;
}