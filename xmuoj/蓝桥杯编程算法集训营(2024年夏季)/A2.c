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
    hpi->length = 0;
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

int compare(const HPI *hpi1, const HPI *hpi2)
{
    if (hpi1->length > hpi2->length) return 1;
    if (hpi1->length < hpi2->length) return -1;
    for (int i = hpi1->length - 1; i >= 0; i--)
    {
        if (hpi1->data[i] > hpi2->data[i]) return 1;
        if (hpi1->data[i] < hpi2->data[i]) return -1;
    }
    return 0;
}


void sub(const HPI *hpi1, const HPI *hpi2, HPI *hpi3) // 仅大减小，hpi1 > hpi2
{
    int len = hpi1->length;
    int borrow = 0;
    for (int i = 0; i < len; i++)
    {
        int temp = hpi1->data[i] - hpi2->data[i] - borrow;
        if (temp < 0)
        {
            temp += 10;
            borrow = 1;
        }
        else borrow = 0;
        hpi3->data[i] = temp;
    }

    // 检查位数
    int i;
    for (i = len - 1; i >= 0; i--)
    {
        if (hpi3->data[i]!= 0)
        {
            hpi3->length = i + 1;
            break;
        }
    }

    if (i == -1) hpi3->length = 1;
}

int main()
{
    HPI hpi1, hpi2, hpi3;
    init(&hpi1);
    init(&hpi2);
    init(&hpi3);
    input(&hpi1);
    input(&hpi2);

    if (compare(&hpi1, &hpi2) < 0)
    {
        printf("-");
        sub(&hpi2, &hpi1, &hpi3);
    }
    else sub(&hpi1, &hpi2, &hpi3);
    print(&hpi3);

    destroy(&hpi1);
    destroy(&hpi2);
    destroy(&hpi3);
    return 0;
}