#include <stdio.h>
static long long count2(long long n)
{
    long long cnt = 0;
    for (long long p = 1; p <= n; p *= 10) {
        long long high = n / p / 10;  
        long long cur  = (n / p) % 10;
        long long low  = n % p;

        if (cur < 2) {
            cnt += high * p;
        } else if (cur == 2) {
            cnt += high * p + low + 1;
        } else {
            cnt += (high + 1) * p;
        }

        if (p > n / 10) {              
            break;
        }
    }
    return cnt;
}

int main(void)
{
    long long L, R;
    if (scanf("%lld %lld", &L, &R) != 2) {
        return 0;
    }

    printf("%lld\n", count2(R) - count2(L - 1));
    return 0;
}
