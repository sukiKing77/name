#include <stdio.h>
static int a[8];        
static int used[9];    
static void dfs(int depth)
{
    if (depth == 8) {
        for (int i = 0; i < 8; i++) {
            if (i) putchar(' ');       
            printf("%d", a[i]);
        }
        putchar('\n');              
        return;
    }
    for (int v = 1; v <= 8; v++) {
        if (!used[v]) {
            used[v] = 1;
            a[depth] = v;
            dfs(depth + 1);
            used[v] = 0;                  
        }
    }
}

int main(void)
{
    dfs(0);
    return 0;
}
