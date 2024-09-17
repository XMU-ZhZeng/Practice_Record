#include <stdio.h>
#include <string.h>

char *end = "12345678x", str[10];
char queue[1000000][10];
int dist[1000000];
int hashSet[10008] = { 0 };
char hashList[10008][100][10];
int h = 0, t = -1;

void swap(char *c1, char *c2) { char tmp = *c1; *c1 = *c2; *c2 = tmp; }

int hash(char *str)
{
    int hashValue = 0;
    for (int i = 0; str[i]; i++) hashValue = (hashValue * 31 + str[i]) % 10007;
    return hashValue;
}


int BFS()
{
    strcpy(queue[++t], str);
    dist[t] = 0;
    if (!strcmp(queue[t], end)) return dist[t]; // 判断
    hashSet[hash(str)]++;
    strcpy(hashList[hash(str)][0], str);

    while (t >= h)
    {
        // 出队
        int p = h;
        ++h;

        int x, y, dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, 1, -1}; // 上、下、左、右
        for (int i = 0; i < 9; i++) if ('x' == queue[p][i]) { x = i / 3, y = i % 3; break; } // 找'x'
        for (int i = 0; i < 4; i++)
        {
            if (x + dx[i] < 0 || x + dx[i] > 2 || y + dy[i] < 0 || y + dy[i] > 2) continue; // 防止越界
            swap(&queue[p][x * 3 + y], &queue[p][(x + dx[i]) * 3 + y + dy[i]]); // 交换
            int ph = hash(queue[p]);
            int flag = 1;
            for (int j = 0; j < hashSet[ph]; j++) flag *= strcmp(hashList[ph][j], queue[p]);
            if (flag)
            {
                strcpy(queue[++t], queue[p]); dist[t] = dist[p] + 1; // 入队
                if (!strcmp(queue[t], end)) return dist[t]; // 判断
                strcpy(hashList[ph][hashSet[ph]++], queue[p]);
            }
            swap(&queue[p][x * 3 + y], &queue[p][(x + dx[i]) * 3 + y + dy[i]]); // 恢复
        }
    }

    return -1;
}

int main()
{
    for (int i = 0; i < 9; i++) scanf(" %c", &str[i]);
    str[9] = 0;

    printf("%d", BFS());

    return 0;
}