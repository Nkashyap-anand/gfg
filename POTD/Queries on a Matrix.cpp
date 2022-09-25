#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> solveQueries(int n, vector<vector<int>> q)
    {
        vector<vector<int>> ans(n, vector<int>(n, 0));

        int N = q.size();
        int m = q[0].size();

        for (int i = 0; i < N; i++)
        {
            int x1 = q[i][0];
            int y1 = q[i][1];
            int x2 = q[i][2];
            int y2 = q[i][3];

            for (int l = x1; l <= x2; l++)
            {
                // first column is +1
                ans[l][y1]++;
                // last+1 will be -1
                if (y2 + 1 < n)
                    ans[l][y2 + 1]--;
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 1; j < n; j++)
            {
                ans[i][j] += ans[i][j - 1];
            }
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
        int n, q;
        cin >> n >> q;
        vector<vector<int>> Queries;
        for (int i = 0; i < q; i++)
        {
            vector<int> cur(4);
            for (int j = 0; j < 4; j++)
                cin >> cur[j];
            Queries.push_back(cur);
        }
        Solution obj;
        vector<vector<int>> ans = obj.solveQueries(n, Queries);
        for (auto i : ans)
        {
            for (auto j : i)
                cout << j << " ";
            cout << "\n";
        }
    }
    return 0;
}