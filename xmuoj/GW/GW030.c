#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    int age1 = 0, age2 = 0, age3 = 0, age4 = 0;

    for (int i = 0; i < n; i++)
    {
        int age;
        scanf("%d", &age);

        if (age <= 18) age1++;
        else if (age <= 35) age2++;
        else if (age <= 60) age3++;
        else age4++;
    }

    printf("%.2lf%%\n", (double)age1 / n * 100);
    printf("%.2lf%%\n", (double)age2 / n * 100);
    printf("%.2lf%%\n", (double)age3 / n * 100);
    printf("%.2lf%%\n", (double)age4 / n * 100);

    return 0;
}