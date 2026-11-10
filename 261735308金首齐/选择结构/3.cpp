#include <stdio.h>
int main(void)
{
    int x, y;
    if (scanf("%d %d", &x, &y) != 2) {
        return 0;
    }

    if (x == y) {
        printf("Tacit£¡\n");    
    } else {
        printf("No Tacit!\n");  
    }

    return 0;
}
