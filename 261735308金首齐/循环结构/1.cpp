#include <stdio.h>
int main(void) {
    int n;
    while (scanf("%d", &n) == 1) {
        int i, j;
       for (i = 0; i < n; ++i) {
            for (j = 0; j < n - 1 - i; ++j) {
                putchar(' ');
            }
            for (j = 0; j < 2 * i + 1; ++j) {
                putchar('*');
            }
            putchar('\n');
        }
        for (i = n - 2; i >= 0; --i) {
            for (j = 0; j < n - 1 - i; ++j) {
                putchar(' ');
            }
            for (j = 0; j < 2 * i + 1; ++j) {
                putchar('*');
            }
            putchar('\n');
        }
    }
    return 0;
}
