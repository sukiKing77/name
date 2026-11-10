#include <stdio.h>
#include <string.h>
#define MAXN 100005
static char s[MAXN];
int main(void)
{
    static const char *word[5] = {"zero", "two", "four", "six", "nine"};
    static const char  dig[5]  = {'0', '2', '4', '6', '9'};
    static const int   len[5]  = {4, 3, 4, 3, 4};

    int T;
    if (scanf("%d", &T) != 1) {
        return 0;
    }

    while (T--) {
        if (scanf("%100000s", s) != 1) {
            break;
        }
        int n = (int)strlen(s);

        for (int i = 0; i < n; ) {
            int matched = 0;

            for (int k = 0; k < 5; k++) {
                if (i + len[k] <= n && strncmp(s + i, word[k], len[k]) == 0) {
                    putchar(dig[k]);        
                    i += len[k];
                    matched = 1;
                    break;
                }
            }

            if (!matched) {
                char c = s[i];
                if (c == '0' || c == '2' || c == '4' || c == '6' || c == '9') {
                    putchar(c);          
                }
                i++;
            }
        }

        putchar('\n');
    }

    return 0;
}
