#include <stdio.h>

int main(void)
{
    int n, x;
    if (scanf("%d %d", &n, &x) != 2) {
        return 0;
    }

    long long cnt = 0;
    for (int i = 1; i <= n; i++) {
        int t = i;
        while (t > 0) {
            if (t % 10 == x) {
                cnt++;          
            }
            t /= 10;
        }
    }

    printf("%lld\n", cnt);
    return 0;
}
