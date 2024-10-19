#include <stdio.h>

void swap(int *e1, int *e2)
{
    int tmp = *e1;
    *e1 = *e2;
    *e2 = tmp;
}

void my_next_permutation(int *arr, int size)
{
    int i;
    for (i = size - 2; i >= 0; i--) if (arr[i] < arr[i  + 1]) break;
    
    if (-1 == i)
    {
        for (int j = 0, k = size - 1; j < k; j++, k--)
            swap(arr + j, arr + k);
        return;
    }

    for (int j = size - 1; j > i; j--)
    {
        if (arr[j] > arr[i])
        {
            swap(arr + j, arr + i);
            break;
        }
    }

    for (int j = i + 1, k = size - 1; j < k; j++, k--) swap(arr + j, arr + k);
}

int main()
{
    int arr[1024];

    int m; scanf("%d", &m);  

    while (m--)
    {
        int n, k; scanf("%d%d", &n, &k);

        for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
        while (k--) my_next_permutation(arr, n);
        for (int i = 0; i < n; i++)
        {
            if (i) printf(" ");
            printf("%d", arr[i]);
        }
        printf("\n");
    }   

    return 0;
}