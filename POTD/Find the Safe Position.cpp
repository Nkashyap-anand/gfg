#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(vector<int> a, int k, int idx)
    {
        if (a.size() == 1)
        {
            return a[0];
        }
        idx = ((idx + k) % a.size());
        a.erase(a.begin() + idx);
        return solve(a, k, idx);
    }

    int safePos(int n, int k)
    {
        int idx = 0;
        k--;
        vector<int> a;
        for (int i = 1; i <= n; i++)
        {
            a.push_back(i);
        }

        int ans = solve(a, k, idx);
        return ans;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;

        cin >> n >> k;

        Solution ob;
        cout << ob.safePos(n, k) << endl;
    }
    return 0;
}