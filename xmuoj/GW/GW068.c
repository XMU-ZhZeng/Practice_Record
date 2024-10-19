#include <stdio.h>
#include <string.h>

int order[7];
char boxs[1000][6][6];

int main()
{
    int f = 0;
    int flag = 0;
    for (int i = 1; i <= 6; i++)
    {
        scanf("%d", &order[i]);
        if (order[i]) flag = 1;
    }

    while (flag)
    {
        memset(boxs, 0, 36000);

        int count = 0;

        for (int i = 6; i >= 1; i--)
        {   
            int j = 0;
            while (order[i]--) // 每次放置一个长宽为 i * i 的产品
            {
                for (; j < count; j++) // 在已有包装箱中寻找位置
                {
                    int flag2 = 0;
                    for (int p = 0; p <= 6 - i; p++)
                    {
                        for (int q = 0; q <= 6 - i; q++)
                        {
                            if (!boxs[j][p][q])
                            {
                                
                                flag2 = 1;

                                for (int r = p; r < p + i; r++)
                                    memset(&boxs[j][r][q], 1, i);
                            }

                            if (flag2) break;
                        }
                        
                        if (flag2) break;
                    }

                    if (flag2) break;
                }

                if (j == count) // 包装箱不够，新增包装箱
                {
                    count++;

                    for (int p = 0; p < i; p++)
                            memset(&boxs[j][p][0], 1, i);
                }
            }
        }

        if (!f)
        {
            printf("%d \n", count);
            f = 1;
        }
        else
            printf("%d\n", count);

        flag = 0;
        for (int i = 1; i <= 6; i++)
        {
            scanf("%d", &order[i]);
            if (order[i]) flag = 1;
        }
    }

    return 0;
}