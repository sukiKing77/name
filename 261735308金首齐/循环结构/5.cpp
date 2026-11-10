#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n;
   while (scanf("%d", &n) == 1) {
        int rows = 2 * n + 1;          
        for (int i = 0; i < rows; i++) {
            int d = abs(i - n);       
            for (int s = 0; s < 2 * d; s++) {
                putchar(' ');          
            }
            for (int s = 0; s < n + 1 - d; s++) {
                putchar('*');         
            }
            putchar('\n');             
        }
    }

    return 0;
}
