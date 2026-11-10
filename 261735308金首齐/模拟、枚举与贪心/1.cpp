#include <stdio.h>
#include <string.h>
static char s[200005];
static int  id[200005];  
static int  fd[200005];   
int main(void)
{
    long long b, t;
    if (scanf("%lld %lld", &b, &t) != 2) {
        return 0;
    }
    if (scanf("%200000s", s) != 1) {
        return 0;
    }

    int len = (int)strlen(s);
    int dot = -1;
    for (int i = 0; i < len; i++) {
        if (s[i] == '.') {
            dot = i;
            break;
        }
    }
    int ik = (dot < 0) ? len : dot;                   
    int m  = (dot < 0) ? 0 : len - dot - 1;        

    for (int i = 0; i < ik; i++) {
        id[i] = s[i] - '0';
    }
    for (int i = 0; i < m; i++) {
        fd[i] = s[dot + 1 + i] - '0';
    }
    int j = -1;
    for (int i = 0; i < m; i++) {
        if (fd[i] >= 5) {
            j = i;
            break;
        }
    }

    int keep = m;                    

    if (j >= 0 && t > 0) {
        long long ops = 0;
        int p = j - 1;                
        while (ops < t && p >= 0) {
            fd[p]++;                 
            ops++;
            keep = p + 1;            
            if (fd[p] == 5) {
                p--;
            } else {
                break;
            }
        }
        if (p < 0 && ops < t) {
            int i = ik - 1;
            while (i >= 0) {
                if (id[i] < 9) {
                    id[i]++;
                    break;
                }
                id[i] = 0;
                i--;
            }
            if (i < 0) {                
                memmove(id + 1, id, (size_t)ik * sizeof(int));
                id[0] = 1;
                ik++;
            }
            keep = 0;
            ops++;
        }
    }

    m = keep;
    while (m > 0 && fd[m - 1] == 0) {   
        m--;
    }

    for (int i = 0; i < ik; i++) {
        putchar('0' + id[i]);
    }
    if (m > 0) {
        putchar('.');
        for (int i = 0; i < m; i++) {
            putchar('0' + fd[i]);
        }
    }
    putchar('\n');

    return 0;
}
