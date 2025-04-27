#include <stdio.h>

int main()
{
    char c[10];
    scanf("%s", c);
    int j = 0;
    for (int i = 0;i < 5;i = j){
        j = i;
        while (c[i] == c[j] && j < 5)
            j++;
        printf("%d%c", j - i, c[i]);
    }
    printf("\n");
    return 0;
}