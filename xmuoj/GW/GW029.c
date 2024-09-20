#include <stdio.h>

int main()
{
    int arr[10];
    for (int i = 0; i < 10; i++) scanf("%d", &arr[i]);

    int high;
    scanf("%d", &high);
    high += 30;


    int count = 0;
    for (int i = 0; i < 10; i++) if (arr[i] <= high) count++;

    printf("%d", count);

    return 0;
}