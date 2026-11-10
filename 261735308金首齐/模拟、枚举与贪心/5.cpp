#include <stdio.h>
int main(void)
{
    long long c[10], p[10];

    for (int i = 0; i < 10; i++) {
        if (scanf("%lld", &c[i]) != 1) {
            return 0;
        }
    }

    int odd = -1, odd_cnt = 0;
    long long pairs = 0;

    for (int i = 0; i < 10; i++) {
        p[i] = c[i] / 2;          
        pairs += p[i];
        if (c[i] % 2) {        
            odd = i;
            odd_cnt++;
        }
    }
    if (odd_cnt > 1) {
        puts("-1");
        return 0;
    }
    if (pairs == 0) {
        if (odd >= 0) {
            printf("%d\n", odd);  
        } else {
            puts("-1");
        }
        return 0;
    }
    int first = -1;
    for (int d = 1; d <= 9; d++) {
        if (p[d] > 0) {
            first = d;
            break;
        }
    }
    if (first < 0) {         
        puts("-1");
        return 0;
    }
    p[first]--;                  
    putchar('0' + first);
    for (int d = 0; d < 10; d++) {
        for (long long k = 0; k < p[d]; k++) {
            putchar('0' + d);
        }
    }
    if (odd >= 0) {
        putchar('0' + odd);
    }
    for (int d = 9; d >= 0; d--) {
        for (long long k = 0; k < p[d]; k++) {
            putchar('0' + d);
        }
    }
    putchar('0' + first);

    putchar('\n');
    return 0;
}
