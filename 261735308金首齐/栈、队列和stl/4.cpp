#include <stdio.h>
#include <stdlib.h>
#include <string.h>
static char s[25][128];
static int cmp(const void *p, const void *q)
{
    const char *a = (const char *)p;    
    const char *b = (const char *)q;
    int la = (int)strlen(a);
    int lb = (int)strlen(b);
    for (int i = 0; i < la + lb; i++) {
        char ca = a[i % la];
        char cb = b[i % lb];
        if (ca != cb) {
            return (ca < cb) ? 1 : -1;    
        }
    }
    return 0;
}

int main(void)
{
    int n;
    if (scanf("%d", &n) != 1) {
        return 0;
    }

    for (int i = 0; i < n; i++) {
        if (scanf("%127s", s[i]) != 1) {
            return 0;
        }
    }

    qsort(s, n, sizeof(s[0]), cmp);

    for (int i = 0; i < n; i++) {
        printf("%s", s[i]);
    }
    printf("\n");

    return 0;
}
