#include <stdio.h>

int main(void)
{
    long long x, y;
    if (scanf("%lld %lld", &x, &y) != 2) {
        return 0;
    }

    if (x > y) {                   
        long long t = x;
        x = y;
        y = t;
    }

    long long cnt = 0;
    for (long long i = x; i <= y; i++) {
        long long t = i, sum = 0;
        while (t > 0) {
            sum += t % 10;
            t /= 10;
        }
        if (sum % 5 == 0) {         
            cnt++;
        }
    }

    printf("%lld\n", cnt);
    return 0;
}
