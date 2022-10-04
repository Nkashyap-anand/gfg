#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
class Solution
{
    long long int givePaths(int i, int j, int m, int n, vector<vector<long long int>> &dp)
    {
        if (i >= m or j >= n)
            return 0;
        if (i == m - 1 and j == n - 1)
            return 1;
        if (dp[i][j] != -1)
            return dp[i][j];
        return dp[i][j] = givePaths(i + 1, j, m, n, dp) % mod + givePaths(i, j + 1, m, n, dp) % mod;
    }

public:
    long long int numberOfPaths(int m, int n)
    {
        vector<vector<long long int>> dp(m, vector<long long int>(n, -1));
        return givePaths(0, 0, m, n, dp) % mod;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> m >> n;
        Solution ob;
        cout << ob.numberOfPaths(m, n) << endl;
    }
    return 0;
}