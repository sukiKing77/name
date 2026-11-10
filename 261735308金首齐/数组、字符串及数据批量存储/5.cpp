#include <stdio.h>
int main(void)
{
    int n;
    if (scanf("%d", &n) != 1) {
        return 0;
    }

    int a = -1, b = -1;            
    for (int i = 0; i < n; i++) {
        int v;
        if (scanf("%d", &v) != 1) {
            return 0;
        }
        a = b;
        b = v;
    }

    if (n == 1) {
       if (b == 0) {
            printf("UP\n");
        } else if (b == 15) {
            printf("DOWN\n");
        } else {
            printf("-1\n");
        }
    } else {
        if (a > b) {        
            printf(a == 1 ? "UP\n" : "DOWN\n");  
        } else {                 
            printf(a == 14 ? "DOWN\n" : "UP\n");   
        }
    }

    return 0;
}
