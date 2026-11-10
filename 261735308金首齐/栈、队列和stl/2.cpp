#include <stdio.h>
#include <stdlib.h>
static int a[100005];
static int diff[100005];
static int cmp_desc(const void *p, const void *q)
{
    int x = *(const int *)p;
    int y = *(const int *)q;
    return (x < y) - (x > y);
}
int main(void)
{
    int n, K;
    if (scanf("%d %d", &n, &K) != 2) {
        return 0;
    }

    for (int i = 0; i < n; i++) {
        if (scanf("%d", &a[i]) != 1) {
            return 0;
        }
    }

    long long total = 0;           
    for (int i = 0; i < n; i++) {
        int b;
        if (scanf("%d", &b) != 1) {
            return 0;
        }
        total += b;
        diff[i] = a[i] - b;      
    }

    qsort(diff, n, sizeof(int), cmp_desc);

    for (int i = 0; i < K; i++) {   
        total += diff[i];
    }

    printf("%lld\n", total);
    return 0;
}
