#include <iostream>

using namespace std;

int arr[1000010];
int q1[1000010], h1 = 0, t1 = -1;
int q2[1000010], h2 = 0, t2 = -1;
int main()
{
    int n, k; cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> arr[i];
  
    q1[t1++] = 0, q2[t2++] = 0;
    for (int i = 1; i < n; i++)
    {
        while (t1 >= h1 && arr[q1[t1]] >= arr[i]) t1--;
        q1[++t1] = i;
     
        if (q1[h1] == i - k) h1++;
        if (i >= k - 1) cout << arr[q1[h1]] << " ";
    }
  
    cout << endl;
  	for (int i = 1; i < n; i++)
    {
        while (t2 >= h2 && arr[q2[t2]] <= arr[i]) t2--;
        q2[++t2] = i; 
      
        if (q2[h2] == i - k) h2++;
        if (i >= k - 1) cout << arr[q2[h2]] << " ";
    }
    
    return 0;
}