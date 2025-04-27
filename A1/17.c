#include <stdio.h>

int main()
{
    int p1[3], p2[3];
    for (int i = 0;i < 3;i++)
        scanf("%d", &p1[i]);
    for (int i = 0;i < 3;i++)
        scanf("%d", &p2[i]);

    for (int i = 0;i < 3;i++)
        if (p1[i] != p2[i]){
            if (p1[i] > p2[i])
                printf("2\n");
            else
                printf("1\n");
            return 0;
        }
    printf("0\n");
    return 0;
}