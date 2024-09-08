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

void add(const HPI *hpi1, const HPI *hpi2, HPI *hpi3)
{
    int carry = 0;
    int len = hpi1->length > hpi2->length? hpi1->length : hpi2->length;
    for (int i = 0; i < len; i++)
    {
        int temp = hpi1->data[i] + hpi2->data[i] + carry;
        hpi3->data[i] = temp % 10;
        carry = temp / 10;
    }
    if (carry) hpi3->data[len++] = carry;
    hpi3->length = len;
}

void print(const HPI *hpi){for (int i = hpi->length - 1; i >= 0; i--) printf("%d", hpi->data[i]);}

int main()
{
    HPI hpi1, hpi2, hpi3;
    init(&hpi1);
    init(&hpi2);
    init(&hpi3);
    input(&hpi1);
    input(&hpi2);
    add(&hpi1, &hpi2, &hpi3);
    print(&hpi3);
    destroy(&hpi1);
    destroy(&hpi2);
    destroy(&hpi3);
    return 0;
}