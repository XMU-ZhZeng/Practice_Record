#include <stdio.h>

int main()
{
    int n; scanf("%d", &n);
    int list[100][2];

    for (int i = 0, idx = 0; i < n; idx = ++i)
    {
        int id, age;
        scanf("%d%d", &id, &age);
        // 插入到合适的位置
        if (age >= 60)
            while (list[idx - 1][1] < age)
                list[idx][0] = list[idx - 1][0], list[idx][1] = list[idx - 1][1], idx--;
        list[idx][0] = id, list[idx][1] = age;
    }

    for (int i = 0; i < n; i++) printf("%06d\n", list[i][0]);

    return 0;
}