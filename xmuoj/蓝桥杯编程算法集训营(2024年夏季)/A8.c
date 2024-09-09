#include <stdio.h>

int e[100000], en[100000];
int head = -1;
int idx = 0;

void front_insert(int x) { e[idx] = x, en[idx] = head, head = idx++; }

void delete_back(int k)
{
    if (0 == k)
        head = en[head];
    else
        en[k - 1] = en[en[k - 1]];
}

void insert(int k, int x) { e[idx] = x, en[idx] = en[k - 1], en[k - 1] = idx++; }

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        char c;
        int k, x;

        scanf("%c", &c);
        while (c == '\n')
            scanf("%c", &c);
        
        switch (c)
        {
        case 'H':
            scanf("%d", &x);
            front_insert(x);
            break;
        case 'D':
            scanf("%d", &k);
            delete_back(k);
            break;
        case 'I':
            scanf("%d %d", &k, &x);
            insert(k, x);
            break;
        }
    }

    for (int i = head; i != -1; i = en[i])
        printf("%d ", e[i]);

    return 0;
}