#include <stdio.h>

int main(void) {
    long long n;
    scanf("%lld", &n);

    if (n % 2 == 1) {
        printf("%lld\n", 3 * n + 1);
    } else {
        printf("%lld\n", n / 2);
    }

    return 0;
}
