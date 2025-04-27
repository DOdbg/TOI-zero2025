#include <stdio.h>
#include <string.h>

int main()
{
    char first_name[50], last_name[50];
    scanf("%s %s", first_name, last_name);
    printf("Hello %s %s\n", first_name, last_name);
    printf("%.2s%.2s\n", first_name, last_name);
    return 0;
}