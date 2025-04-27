#include <stdio.h>
#include <string.h>

int main()
{
    char a[50], b[50];
    int age;
    scanf("%s %s %d", a, b, &age);
    
    if (strlen(a) >= 5)
        printf("%.2s%c%d\n", a, b[strlen(b) - 1], age % 10);
    else
        printf("%.1s%d%c\n", a, age, b[strlen(b) - 1]);
    return 0;
}