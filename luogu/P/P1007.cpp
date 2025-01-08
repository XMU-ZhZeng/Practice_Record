#include <iostream>
#include <algorithm>

using namespace std;

int L, N;
int arr[5050] = { 0 };

int main()
{
    cin >> L >> N;
    for (int i = 0; i < N; i++)
    {
        int x; cin >> x;
        arr[x] = 1;
    }
    
    int Max = 0, Min = 0;
    for (int i = 1; i <= L; i++)
    {
        if (arr[i])
        {
            Max = max(Max, max(i, L+1-i));
            Min = max(Min, min(i, L+1-i));
        }
    }
    
    cout << Min << " " << Max << endl;
    
    return 0;
}