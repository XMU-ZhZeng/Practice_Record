#include <iostream>
using namespace std;
#include <vector>
#include <string>

vector<string> v;
int position[8] = { 0 };
char chessboard[9][9] = { 0 };

void dfs(int depth, int step)
{
    if (step == depth)
    {
        string str;
        for (int i = 0; i < depth; i++) str += position[i] + '0';
        v.push_back(str);
        return;
    }

    for (int i = 1; i <= 8; i++)
    {
        if (chessboard[step + 1][i]) continue;

        position[step] = i;

        for (int j = step + 2, k = 1; j <= depth; j++, k++)
        {
            chessboard[j][i] += 1;
            if (i - k >= 1) chessboard[j][i - k] += 1;
            if (i + k <= 8) chessboard[j][i + k] += 1;
        }

        dfs(depth, step + 1);

        position[step] = 0;

        for (int j = step + 2, k = 1; j <= depth; j++, k++)
        {
            chessboard[j][i] -= 1;
            if (i - k >= 1) chessboard[j][i - k] -= 1;
            if (i + k <= 8) chessboard[j][i + k] -= 1;
        }
    }
}

int main()
{
    int T; scanf("%d", &T);

    dfs(8, 0);

    while (T--)
    {
        int n; scanf("%d", &n);
        cout << v[n - 1] << endl;
    }

    return 0;
}