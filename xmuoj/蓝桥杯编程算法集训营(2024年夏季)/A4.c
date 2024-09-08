#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define MAX 100000

typedef struct HighPrecisionInteger
{
    char *data;
    int length;
}HPI;

void init(HPI *hpi)
{
    hpi->data = (char *)malloc(sizeof(char) * MAX);
    memset(hpi->data, 0, sizeof(char) * MAX);
    hpi->length = 1;
}

void input(HPI *hpi)
{
    scanf("%s", hpi->data);
    hpi->length = strlen(hpi->data);
    for (int i = 0; i < hpi->length; i++) hpi->data[i] -= '0';
    for (int i = 0, j = hpi->length - 1; i < j; i++, j--)
    {
        char temp = hpi->data[i];
        hpi->data[i] = hpi->data[j];
        hpi->data[j] = temp;
    }
}

void destroy(HPI *hpi){free(hpi->data);}

void print(const HPI *hpi){for (int i = hpi->length - 1; i >= 0; i--) printf("%d", hpi->data[i]);}

int divide(HPI *hpi1, int num, HPI *hpi2)
{
    int r = 0;
    for (int i = hpi1->length - 1; i >= 0; i--)
    {
        r = r * 10 + hpi1->data[i];
        hpi2->data[i] = r / num;
        r %= num;
    }

    int len = hpi1->length - 1;
    while (len >= 0 && hpi2->data[len] == 0) len--;
    hpi2->length = len + 1;
    if (hpi2->length == 0) hpi2->length = 1;
    return r;
}

int main()
{
    HPI hpi1, hpi2;
    init(&hpi1);
    init(&hpi2);
    input(&hpi1);

    int num;
    scanf("%d", &num);

    int res = divide(&hpi1, num, &hpi2);

    print(&hpi2);
    printf("\n");
    printf("%d", res);

    destroy(&hpi1);
    destroy(&hpi2);
    return 0;
}