#include <stdio.h>
#include <string.h>

int main()
{
    char c[10];
    scanf("%s", c);
    int n = strlen(c);
    
    for (int i = 0;i < n;i++){
        if (n - i == 3)
            printf(",");
        printf("%c", c[i]);
    }

    return 0;
}