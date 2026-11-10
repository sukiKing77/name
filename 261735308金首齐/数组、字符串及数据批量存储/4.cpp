#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int l, r;
} Seg;

static int cmp(const void *a, const void *b)
{
    const Seg *p = (const Seg *)a;
    const Seg *q = (const Seg *)b;
    if (p->l != q->l) return (p->l < q->l) ? -1 : 1;
    if (p->r != q->r) return (p->r < q->r) ? -1 : 1;
    return 0;
}

int main(void)
{
    int L, M;
    if (scanf("%d %d", &L, &M) != 2) {
        return 0;
    }

    Seg s[105];
    for (int i = 0; i < M; i++) {
        if (scanf("%d %d", &s[i].l, &s[i].r) != 2) {
            return 0;
        }
    }

    qsort(s, M, sizeof(Seg), cmp);    

    long long removed = 0;             
    int curL = s[0].l, curR = s[0].r;

    for (int i = 1; i < M; i++) {
        if (s[i].l <= curR) {         
            if (s[i].r > curR) {
                curR = s[i].r;
            }
        } else {                       
            removed += (long long)curR - curL + 1;
            curL = s[i].l;
            curR = s[i].r;
        }
    }
    removed += (long long)curR - curL + 1;   

    printf("%lld\n", (long long)L + 1 - removed);
    return 0;
}
