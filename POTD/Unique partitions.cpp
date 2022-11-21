#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> ans;

    void helper(int num, int target, vector<int> &v)
    {
        if (target == 0)
        {
            ans.push_back(v);
            return;
        }

        if (num == 0)
            return;

        if (target >= num)
        {
            v.push_back(num);
            helper(num, target - num, v);
            v.pop_back();
        }

        helper(num - 1, target, v);
    }

    vector<vector<int>> UniquePartitions(int n)
    {

        vector<int> v;
        helper(n, n, v);

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
        Solution ob;
        vector<vector<int>> ans = ob.UniquePartitions(n);
        for (auto i : ans)
            for (auto j : i)
                cout << j << " ";
        cout << "\n";
    }
    return 0;
}
