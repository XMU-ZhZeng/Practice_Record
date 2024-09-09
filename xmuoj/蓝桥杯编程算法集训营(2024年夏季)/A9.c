#include <stdio.h>

int e[100000], el[100000], er[100000];
int lhead = -1, rhead = -1;
int idx = 0;

void lhead_insert(int x)
{
    e[idx] = x, er[idx] = lhead, el[idx] = -1;
    if (lhead != -1)
        el[lhead] = idx;
    else
        rhead = idx;
    lhead = idx++;
}

void rhead_insert(int x)
{
    e[idx] = x, el[idx] = rhead, er[idx] = -1;
    if (rhead != -1)
        er[rhead] = idx;
    else
        lhead = idx;
    rhead = idx++;
}

void delete(int k)
{
    if (el[k - 1] != -1) er[el[k - 1]] = er[k - 1];
    else lhead = er[k - 1];
    if (er[k - 1] != -1) el[er[k - 1]] = el[k - 1];
    else rhead = el[k - 1];
}
void left_insert(int k, int x)
{
    e[idx] = x, er[idx] = k - 1, el[idx] = el[k - 1];
    if (el[k - 1] != -1) er[el[k - 1]] = idx;
    else lhead = idx;
    el[k - 1] = idx++;
}

void right_insert(int k, int x)
{
    e[idx] = x, er[idx] = er[k - 1], el[idx] = k - 1;
    if (er[k - 1] != -1) el[er[k - 1]] = idx;
    else rhead = idx;
    er[k - 1] = idx++;
}

int main()
{
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        char c;
        int k, x;

        scanf(" %c", &c);

        switch (c)
        {
        case 'L':
            scanf("%d", &x);
            lhead_insert(x);
            break;
        case 'R':
            scanf("%d", &x);
            rhead_insert(x);
            break;
        case 'D':
            scanf("%d", &k);
            delete (k);
            break;
        case 'I':
            scanf("%c", &c);
            if (c == 'L')
            {
                scanf("%d %d", &k, &x);
                left_insert(k, x);
            }
            else if (c == 'R')
            {
                scanf("%d %d", &k, &x);
                right_insert(k, x);
            }
            break;
        }
    }

    for (int i = lhead; i != -1; i = er[i])
        printf("%d ", e[i]);

    return 0;
}