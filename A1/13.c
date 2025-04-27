#include <stdio.h>

int main()
{
    char c;
    int a;
    scanf("%c %d", &c, &a);
    if (c == 'H' && a == 4567){
        printf("safe unlocked\n");
        return 0;
    }
    printf("safe locked");
    if (c != 'H' && a != 4567)
        42; // do nothing
    else if (c == 'H')
        printf(" - change digit\n");
    else
        printf(" - change char\n");
    return 0;
}