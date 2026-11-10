#include <stdio.h>

int main(void) {
    long long a, b;
    scanf("%lld %lld", &a, &b);

    if (a < b) 
	{
        printf("<\n");
    } 
	else if (a == b) 
	{
        printf("=\n");
    } 
	else
	 {
        printf(">\n");
    }

    return 0;
}
