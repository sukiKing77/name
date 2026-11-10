#include <stdio.h>
#include <stdlib.h>
static long long a[100005];
static int cmp_asc(const void *p, const void *q)
{
    long long x = *(const long long *)p;
    long long y = *(const long long *)q;
    return (x > y) - (x < y);
}
int main(void)
{
    int n;
    if (scanf("%d", &n) != 1) {
        return 0;
    }

    for (int i = 0; i < n; i++) {
        if (scanf("%lld", &a[i]) != 1) {
            return 0;
        }
    }

    qsort(a, n, sizeof(long long), cmp_asc);
    for (int i = 0; i + 2 < n; i++) {
        if (a[i] + a[i + 1] > a[i + 2]) {
            printf("%lld %lld %lld\n", a[i], a[i + 1], a[i + 2]);
            return 0;
        }
    }
    printf("No solution\n");
    return 0;
}
