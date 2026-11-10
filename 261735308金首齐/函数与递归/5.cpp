#include <stdio.h>
#include <string.h>
static void big_mul(const char *a, const char *b, char *out)
{
    int la = (int)strlen(a);
    int lb = (int)strlen(b);
    int d[128] = {0};                       
    for (int i = la - 1; i >= 0; i--) {
        for (int j = lb - 1; j >= 0; j--) {
            d[i + j + 1] += (a[i] - '0') * (b[j] - '0');
        }
    }
    for (int k = la + lb - 1; k > 0; k--) {
        d[k - 1] += d[k] / 10;
        d[k] %= 10;
    }
    int p = 0;
    while (p < la + lb - 1 && d[p] == 0) {
        p++;
    }
    int q = 0;
    for (int k = p; k < la + lb; k++) {
        out[q++] = (char)('0' + d[k]);
    }
    out[q] = '\0';
}

int main(void)
{
    int T;
    if (scanf("%d", &T) != 1) {
        return 0;
    }

    while (T--) {
        char a[64], b[64], res[128];
        if (scanf("%63s %63s", a, b) != 2) {
            break;
        }

        big_mul(a, b, res);
        printf("%s\n", res);
    }

    return 0;
}
