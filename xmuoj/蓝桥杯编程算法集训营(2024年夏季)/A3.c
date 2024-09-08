#include<stdio.h>
#include<stdlib.h>
#include<string.h>
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

void clear(HPI *hpi)
{
    if (hpi->length == 1 && hpi->data[0] == 0) return;
    memset(hpi->data, 0, sizeof(char) * MAX);
    hpi->length = 1;
}

void multi(const HPI *hpi1, const HPI *hpi2, HPI *hpi3)
{
    clear(hpi3);
    for (int i = 0; i < hpi1->length; i++)
    {
        for (int j = 0; j < hpi2->length; j++)
        {
            hpi3->data[i + j] += hpi1->data[i] * hpi2->data[j];
            hpi3->data[i + j + 1] += hpi3->data[i + j] / 10;
            hpi3->data[i + j] %= 10;
        }
    }

    if (hpi3->data[hpi1->length + hpi2->length - 1]) hpi3->length = hpi1->length + hpi2->length;
    else hpi3->length = hpi1->length + hpi2->length - 1;
}

int main()
{
    HPI hpi1, hpi2, hpi3;
    init(&hpi1);
    init(&hpi2);
    init(&hpi3);
    input(&hpi1);
    input(&hpi2);

    multi(&hpi1, &hpi2, &hpi3);

    print(&hpi3);

    destroy(&hpi1);
    destroy(&hpi2);
    destroy(&hpi3);
    return 0;
}