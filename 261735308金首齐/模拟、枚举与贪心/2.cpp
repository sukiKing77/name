#include <stdio.h>
#include <string.h>
static int mid[10][10];  
int main(void)
{
    mid[1][3] = mid[3][1] = 2;
    mid[4][6] = mid[6][4] = 5;
    mid[7][9] = mid[9][7] = 8;

    mid[1][7] = mid[7][1] = 4;
    mid[2][8] = mid[8][2] = 5;
    mid[3][9] = mid[9][3] = 6;

    mid[1][9] = mid[9][1] = 5;
    mid[3][7] = mid[7][3] = 5;

    char s[40];
    while (scanf("%39s", s) == 1) {
        int used[10] = {0};
        int ok = 1;
        int n = (int)strlen(s);

        for (int i = 0; i < n; i++) {
            if (s[i] < '1' || s[i] > '9') {  
                ok = 0;
                break;
            }
        }

        if (ok) {
            used[s[0] - '0'] = 1;             
            for (int i = 1; i < n; i++) {
                int a = s[i - 1] - '0';
                int b = s[i] - '0';

                if (used[b]) {              
                    ok = 0;
                    break;
                }
                int m = mid[a][b];
                if (m != 0 && !used[m]) {    
                    ok = 0;
                    break;
                }
                used[b] = 1;
            }
        }

        printf("%s\n", ok ? "YES" : "NO");
    }

    return 0;
}
