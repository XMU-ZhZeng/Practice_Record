#include <stdio.h>

int is_leap_year(int year) { return year % 4 == 0 && year % 100!= 0 || year % 400 == 0; }

int month[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main()
{
    int y, m, d;
    while(scanf("%d/%d/%d", &y, &m, &d)!= EOF)
    {
        int days = 0;
        for (int i = 1; i < m; i++) days += month[i];
        if (m > 2 && is_leap_year(y)) days++;
        days += d;
        printf("%d\n", days);
    }

    return 0;
}