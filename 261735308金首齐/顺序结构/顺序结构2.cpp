#include <stdio.h>

int addNumber(int n, int *mask)
{
    while (n > 0) {
        int digit = n % 10;

        if (digit == 0 || (*mask & (1 << digit))) {
            return 0;
        }

        *mask |= 1 << digit;
        n /= 10;
    }
    return 1;
}

int main(void)
{
    for (int result = 1000; result <= 9999; result++) {
        for (int a = 1; a * a <= result; a++) {
            if (result % a != 0) {
                continue;
            }

            int b = result / a;
            int mask = 0;

            if (addNumber(a, &mask) &&
                addNumber(b, &mask) &&
                addNumber(result, &mask) &&
                mask == 0x3FE) {  
                printf("%d = %d x %d\n", result, a, b);
            }
        }
    }

    return 0;
}
