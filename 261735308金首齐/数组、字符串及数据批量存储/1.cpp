#include <stdio.h>
static char ibuf[1 << 16];
static int  ilen = 0, ipos = 0;

static int next_char(void)
{
    if (ipos == ilen) {
        ilen = (int)fread(ibuf, 1, sizeof ibuf, stdin);
        ipos = 0;
        if (ilen <= 0) return -1;
    }
    return (unsigned char)ibuf[ipos++];
}

static int read_ll(long long *out)
{
    int c, neg = 0;
    long long x = 0;
    do {
        c = next_char();
    } while (c != -1 && (c < '0' || c > '9') && c != '-');
    if (c == -1) return 0;
    if (c == '-') { neg = 1; c = next_char(); }
    while (c >= '0' && c <= '9') {
        x = x * 10 + (c - '0');
        c = next_char();
    }
    *out = neg ? -x : x;
    return 1;
}

int main(void)
{
    long long tmp, T;
    if (!read_ll(&tmp)) return 0;
    T = tmp;

    while (T-- > 0) {
        long long n;
        if (!read_ll(&n)) break;

        long long sum = 0;          
        __int128  sq  = 0;          
        long long mn = 0, mx = 0;

        for (long long i = 0; i < n; i++) {
            long long a;
            if (!read_ll(&a)) return 0;
            sum += a;
            sq  += (__int128)a * a;
            if (i == 0) { mn = mx = a; }
            else {
                if (a < mn) mn = a;
                if (a > mx) mx = a;
            }
        }

        long long range = mx - mn;  
        __int128 num = (__int128)n * sq - (__int128)sum * sum;
        __int128 den = (__int128)n * n;

        long long ip  = (long long)(num / den);    
        __int128  rem = num % den;                
        __int128 frac = (rem * 2000 + den) / (den * 2);
        if (frac >= 1000) {                        
            ip++;
            frac -= 1000;
        }

        printf("%lld %lld.%03lld\n", range, ip, (long long)frac);
    }

    return 0;
}
