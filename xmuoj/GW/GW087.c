#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    int x1;
    int x2;
    int h;
} Platform;

typedef struct {
    int x;
    int PlatformIndex;
} Position;

// 定义向左向右的标志
#define LEFT 0
#define RIGHT 1

// 递归函数，类似 C++中的 bfs
int findMinTime(Position p, Platform* platforms, int numPlatforms, int time, int maxHeightDiff) {
    static int minTime = __INT_MAX__;

    if (platforms[p.PlatformIndex].h == 0) {
        if (time < minTime) minTime = time;
        return minTime;
    }

    // 向左
    int idx = p.PlatformIndex;
    int x = platforms[p.PlatformIndex].x1;
    int Time = time + abs(x - p.x);
    for (int i = idx + 1; i < numPlatforms; i++) {
        if (platforms[i].x1 <= x && platforms[i].x2 >= x) {
            if (platforms[idx].h - platforms[i].h <= maxHeightDiff) {
                Position newPosition = {x, i};
                findMinTime(newPosition, platforms, numPlatforms, Time + platforms[idx].h - platforms[i].h, maxHeightDiff);
            }
            break;
        }
    }

    // 向右
    idx = p.PlatformIndex;
    x = platforms[p.PlatformIndex].x2;
    Time = time + abs(x - p.x);
    for (int i = idx + 1; i < numPlatforms; i++) {
        if (platforms[i].x1 <= x && platforms[i].x2 >= x) {
            if (platforms[idx].h - platforms[i].h <= maxHeightDiff) {
                Position newPosition = {x, i};
                findMinTime(newPosition, platforms, numPlatforms, Time + platforms[idx].h - platforms[i].h, maxHeightDiff);
            }
            break;
        }
    }

    return minTime;
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, x, y, max;
        scanf("%d %d %d %d", &n, &x, &y, &max);

        Platform* platforms = (Platform*)malloc((n + 1) * sizeof(Platform));
        for (int i = 0; i < n; i++) {
            int x1, x2, h;
            scanf("%d %d %d", &x1, &x2, &h);
            platforms[i].x1 = x1;
            platforms[i].x2 = x2;
            platforms[i].h = h;
        }
        // 地面
        platforms[n].x1 = -20000;
        platforms[n].x2 = 20000;
        platforms[n].h = 0;

        // 排序，从高到低
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (platforms[i].h < platforms[j].h) {
                    Platform temp = platforms[i];
                    platforms[i] = platforms[j];
                    platforms[j] = temp;
                }
            }
        }

        // 寻找第一次可以到达的平台
        int time = 0, idx = 0;
        for (int i = 0; i < n; i++) {
            if (platforms[i].x1 <= x && platforms[i].x2 >= x) {
                time = y - platforms[i].h;
                idx = i;
                break;
            }
        }

        Position startPosition = {x, idx};
        int result = findMinTime(startPosition, platforms, n + 1, time, max);
        printf("%d\n", result);

        free(platforms);
    }

    return 0;
}