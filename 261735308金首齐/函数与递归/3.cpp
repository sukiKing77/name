#include <stdio.h>
typedef unsigned long long u64;
typedef __int128           i128;
static u64 mul_mod(u64 a, u64 b, u64 m)
{
    return (u64)((i128)a * b % m);
}
static u64 pow_mod(u64 a, u64 e, u64 m)
{
    u64 r = 1 % m;
    a %= m;
    while (e) {
        if (e & 1) r = mul_mod(r, a, m);
        a = mul_mod(a, a, m);
        e >>= 1;
    }
    return r;
}
static int is_prime(u64 n)
{
    static const u64 base[12] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};

    if (n < 2) return 0;
    for (int i = 0; i < 12; i++) {
        if (n % base[i] == 0) {
            return (n == base[i]);
        }
    }

    u64 d = n - 1;
    int s = 0;
    while ((d & 1) == 0) {    
        d >>= 1;
        s++;
    }
    for (int i = 0; i < 12; i++) {
        u64 a = base[i];
        u64 x = pow_mod(a, d, n);
        if (x == 1 || x == n - 1) continue;

        int composite = 1;
        for (int r = 1; r < s; r++) {
            x = mul_mod(x, x, n);
            if (x == n - 1) {   
                composite = 0;
                break;
            }
        }
        if (composite) return 0;
    }
    return 1;
}

int main(void)
{
    u64 t;
    if (scanf("%llu", &t) != 1) {
        return 0;
    }
    int dig[20], len = 0;
    u64 tmp = t;
    while (tmp > 0) {
        dig[len++] = (int)(tmp % 10);
        tmp /= 10;
    }
    u64 pal = t;
    for (int i = 1; i < len; i++) {
        pal = pal * 10 + dig[i];
    }

    printf("%s\n", is_prime(pal) ? "prime" : "noprime");
    return 0;
}
