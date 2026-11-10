#include <stdio.h>

static char s[100005];

int main(void)
{
    if (scanf("%100000s", s) != 1) {
        return 0;
    }

    long long bal = 0;          
    int ok = 1;

    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == 'a') {
            bal++;
        } else if (s[i] == 'b') {
            bal--;
        } else {              
            ok = 0;
            break;
        }

        if (bal < 0) {          
            ok = 0;
            break;
        }
    }

    printf("%s\n", (ok && bal == 0) ? "Good" : "Bad");
    return 0;
}
