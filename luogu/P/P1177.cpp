#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int N;
vector<int> arr;

void ShellSort()
{
    int t = 0;
    while ((int)pow(2, t) < N) t++;
    t--;

    while (t)
    {
        int dlta = (int)pow(2, t) - 1;

        for (int i = dlta; i < N; i++)
        {
            int j = i;
            while (j - dlta >= 0 && arr[j] < arr[j - dlta])
            {
                int tmp = arr[j];
                arr[j] = arr[j - dlta];
                arr[j - dlta] = tmp;
                j -= dlta;
            }
        }

        t--;
    }
}

int main()
{
    cin >> N;
    int x;
    for (int i = 0; i < N; i++)
    {
        cin >> x;
        arr.push_back(x);
    }

    ShellSort();

    for (int i = 0; i < N; i++)
    {
        if (i) cout << " ";
        cout << arr[i];
    }
    cout << endl;

    return 0;
}