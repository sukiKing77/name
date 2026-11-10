#include <stdio.h>

int main(void)
{
    int n;
    if (scanf("%d", &n) != 1) {
        return 0;
    }

    int num = 1;                       
    for (int i = 1; i <= n; i++) {    
        for (int j = 1; j <= i; j++) {
            printf("%4d", num++);     
        }
        printf("\n");
    }

    return 0;
}
