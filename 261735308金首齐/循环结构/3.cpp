#include <stdio.h>

int main(void)
{
    char ch;
    if (scanf(" %c", &ch) != 1) {
        return 0;
    }

    int n = ch - 'A' + 1;         
    for (int i = 1; i <= n; i++) {
        for (int s = 0; s < n - i; s++) {
            putchar(' ');         
        }
        for (int j = 0; j < i; j++) {
            putchar('A' + j);      
        }
        for (int j = i - 2; j >= 0; j--) {
            putchar('A' + j);      
        }
        putchar('\n');
    }

    return 0;
}
