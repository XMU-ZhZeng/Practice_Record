#include <iostream>
#include <vector>

using namespace std;

int binarySearch(int *base, int size, int num)
{
    int l = 0, r = size - 1;
    while (r - l > 1)
    {
        int mid = (r + l) / 2;
        if (base[mid] <= num) r = mid;
        else l = mid;
    }

    if (base[l] <= num) return l;
    return r;
}

int dp[10010], nums[10010];

int main()
{
    int count = 0;
    while (scanf("%d", &nums[count]) != EOF) count++;

    int len = 1;
    dp[0] = nums[0];
    for (int i = 1; i < count; i++)
    {
        if (nums[i] < dp[len - 1]) dp[len++] = nums[i];
        else dp[binarySearch(dp, len, nums[i])] = nums[i];
    }
    printf("%d\n", len);

    vector<int> v(nums, nums + count);

    count = 0;
    while (v.size())
    {
        count++;
        int tmp = v[0];
        v.erase(v.begin());

        for (vector<int>::iterator it = v.begin(); it != v.end();)
        {
            if (*it < tmp)
            {
                tmp = *it;
                v.erase(it);
            }
            else it++;
        }
    }
    printf("%d", count);

    return 0;
}