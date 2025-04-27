#include <stdio.h>

int main()
{
    char a;
    scanf("%c", &a);
    if (a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u')
        printf("yes\n");
    else
        printf("no\n");    
    return 0;
}