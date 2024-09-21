#include <stdio.h>

int arr[100010];

void qSort(int l, int r)
{
    if (l >= r) return;
    int i = l, j = r;
    int mid = arr[l];
    while (i < j)
    {
        while (i < j && arr[j] >= mid) j--;
        arr[i] = arr[j];
        while (i < j && arr[i] <= mid) i++;
        arr[j] = arr[i];
    }
    arr[i] = mid;
    qSort(l, i - 1);
    qSort(i + 1, r);
}

int main()
{
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    qSort(0, n - 1);

    int k;
    scanf("%d", &k);

    for (int i = n - 1; i >= n - k; i--) printf("%d\n", arr[i]);

    return 0;
}