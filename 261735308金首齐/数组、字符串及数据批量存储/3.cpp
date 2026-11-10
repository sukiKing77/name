#include <stdio.h>

int main(void)
{
    int n, k, m;
    if (scanf("%d %d %d", &n, &k, &m) != 3) {
        return 0;
    }

    int a[105];
    for (int i = 0; i < n; i++) {
        a[i] = i;                 
    }

    int size = n;
    int idx = k;                   

    while (size > 1) {
        idx = (idx + m - 1) % size;   

        for (int i = idx; i < size - 1; i++) {
            a[i] = a[i + 1];          
        }
        size--;
        if (idx == size) {
            idx = 0;
        }
    }

    printf("%d\n", a[0]);
    return 0;
}
