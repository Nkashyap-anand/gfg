#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countTriplets(vector<int> nums)
    {

        int small = 0, large = 0, ans = 0;

        for (int i = 1; i < nums.size() - 1; ++i)
        {
            small = 0;
            large = 0;

            for (int j = 0; j < i; ++j)
            {
                if (nums[j] < nums[i])
                    small++;
            }

            for (int j = i + 1; j < nums.size(); ++j)
            {
                if (nums[j] > nums[i])
                    large++;
            }

            ans += (small * large);
        }
        return ans;
    }
};

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (int i = 0; i < n; i++)
            cin >> nums[i];
        Solution ob;
        int ans = ob.countTriplets(nums);
        cout << ans << "\n";
    }
    return 0;
}