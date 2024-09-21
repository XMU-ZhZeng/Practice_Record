#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int k;
    cin >> k;

    vector<int> nums;
    for (int i = 0; i < k; i++)
    {
        int num;
        cin >> num;
        nums.push_back(num);
    }

    vector<int> dp(k, 1);
    for (int i = 1; i < k; i++)
        for (int j = 0; j < i; j++)
            if (nums[i] <= nums[j])
                dp[i] = max(dp[i], dp[j] + 1);

    int maxLength = 0;
    for (int i = 0; i < k; i++)
        maxLength = max(maxLength, dp[i]);

    cout << maxLength << endl;

    return 0;
}