#include <stdio.h>

int main()
{
    int money;
    scanf("%d", &money);
    static int coin[4] = {10, 5, 2, 1};

    for (int i = 0;i < 4;i++){
        printf("%d = %d\n", coin[i], money / coin[i]);
        money %= coin[i];
    }
    
    return 0;
}