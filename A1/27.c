#include <stdio.h>

int main()
{
    char c[10];
    scanf("%s", c);
    
    for (int i = 4;i >= 0;i--){
        if ('A' <= c[i] && c[i] <= 'Z')
            printf("%c", c[i] + 32);
        else
            printf("%c", c[i]);
    }
    return 0;
}