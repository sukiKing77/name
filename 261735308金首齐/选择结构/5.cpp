#include <stdio.h>

int main(void) {
    long long X, Y;
    scanf("%lld %lld", &X, &Y);

    long long Z;
    if (Y % X == 0) {
        Z = X + Y;
    } else {
        Z = Y - X;
    }

    printf("%lld\n", Z);
    return 0;
}
