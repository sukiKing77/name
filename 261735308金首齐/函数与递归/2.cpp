#include <stdio.h>
static int days_in_month(int y, int m)
{
    static const int days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (m == 2) {
        int leap = (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
        return leap ? 29 : 28;
    }
    return days[m];
}

int main(void)
{
    int y, m, x;
    while (scanf("%d %d %d", &y, &m, &x) == 3) {
        int dim = days_in_month(y, m);
        int cnt = 0;
        char buf[16];

        for (int d = 1; d <= dim; d++) {
            sprintf(buf, "%04d-%02d-%02d", y, m, d);
            for (int i = 0; buf[i] != '\0'; i++) {
                if (buf[i] == '0' + x) {
                    cnt++;
                }
            }
        }

        printf("%d\n", cnt);
    }

    return 0;
}
