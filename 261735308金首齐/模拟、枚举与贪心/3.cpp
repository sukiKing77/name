#include <stdio.h>

static char s[20005];

int main(void)
{
    int n = 0, ch;

    
    while ((ch = getchar()) != EOF) {
        if (n < (int)sizeof(s) - 1) {
            s[n++] = (char)ch;
        }
    }

    int i = 0;
    while (i < n) {
       
        if (s[i] == '"' && (i == 0 || s[i - 1] != '\\')) {
            putchar(s[i]);
            i++;
            while (i < n) {
                putchar(s[i]);
                if (s[i] == '"') {     
                    i++;
                    break;
                }
                i++;
            }
        }
  
        else if (s[i] == '/' && i + 1 < n && s[i + 1] == '*') {
            int j = i + 2, close = -1;
            while (j + 1 < n) {
                if (s[j] == '*' && s[j + 1] == '/') {
                    close = j;
                    break;
                }
                j++;
            }
            if (close < 0) {
             for (; i < n; i++) {
                    putchar(s[i]);
                }
            } else {
                i = close + 2;         
            }
        }
     
        else {
            putchar(s[i]);
            i++;
        }
    }

    return 0;
}
