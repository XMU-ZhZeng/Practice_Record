#include <iostream>
#include <algorithm>

using namespace std;

struct Cow
{
    int W, S;
};
int N;
Cow cow[50010];

bool compare(Cow& c1, Cow& c2) { return (c1.W + c1.S) > (c2.W + c2.S);}

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++) cin >> cow[i].W >> cow[i].S;
  
    sort(cow, cow + N, compare);
  
    int sumW = 0, max = -1e9;
    for (int i = N - 1; i >= 0; i--)
    {
        max = max > sumW - cow[i].S ? max : sumW - cow[i].S;
        sumW += cow[i].W;
    }
  
    cout << max;
  
    return 0;
}