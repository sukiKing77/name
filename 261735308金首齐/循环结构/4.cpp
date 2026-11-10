#include <stdio.h>
int main(void)
{
    int T;
    if (scanf("%d", &T) != 1) {
        return 0;                    
    }

    while (T--) {
        int n;
        if (scanf("%d", &n) != 1) {
            break;
        }

        int mid = n / 2;              
        for (int i = 0; i < n; i++) {
          int k = (i <= mid) ? i : n - 1 - i;

            for (int s = 0; s < mid - k; s++) {
                putchar(' ');       
            }
            for (int s = 0; s < 2 * k + 1; s++) {
                putchar('*');         
            }
            putchar('\n');           
        }
    }

    return 0;
}
