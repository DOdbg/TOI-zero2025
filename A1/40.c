#include <stdio.h>

int main()
{
    int ans = 0;
    static int a[] = {0, 100, 120, 200, 60};
    while (1){
        int t;
        scanf("%d", &t);
        if (t == 5){
            printf("Bye Bye\n");
            printf("Total Calories: %d\n", ans);
            break;
        }
        ans += a[t];
    }
    return 0;
}