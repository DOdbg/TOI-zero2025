#include <stdio.h>

int main()
{
    int d;
    char temp;
    scanf("%d %c", &d, &temp);
    if (temp == 'f' || temp == 'F'){
        if (32 < d && d < 212)
            printf("liquid");
        else if (d <= 32)
            printf("solid\n");
        else
            printf("gas\n");
    }
    else {
        if (d < 0)
            printf("solid\n");
        else if (d < 100)
            printf("liquid\n");
        else
            printf("gas\n");
    }
    return 0;
}