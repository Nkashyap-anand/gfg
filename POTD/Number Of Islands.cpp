#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void solve(vector<vector<int>> &v, int i, int j)
    {
        if (i < 0 || j < 0 || i >= v.size() || j >= v[0].size() || !v[i][j])
            return;

        v[i][j] = 0;

        solve(v, i + 1, j);
        solve(v, i, j + 1);
        solve(v, i - 1, j);
        solve(v, i, j - 1);
    }

    int noIslands(vector<vector<int>> v)
    {
        int ans = 0;
        for (int i = 0; i < v.size(); i++)
        {
            for (int j = 0; j < v[0].size(); j++)
            {
                if (v[i][j])
                {
                    ans++;
                    solve(v, i, j);
                }
            }
        }
        return ans;
    }
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators)
    {
        // code here
        vector<int> ans;
        vector<vector<int>> v(n, vector<int>(m, 0));
        for (int i = 0; i < operators.size(); i++)
        {
            v[operators[i][0]][operators[i][1]] = 1;
            ans.push_back(noIslands(v));
        }
        return ans;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, k;
        cin >> n >> m >> k;
        vector<vector<int>> a;

        for (int i = 0; i < k; i++)
        {
            vector<int> temp;
            for (int j = 0; j < 2; j++)
            {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            a.push_back(temp);
        }

        Solution obj;
        vector<int> res = obj.numOfIslands(n, m, a);

        for (auto x : res)
            cout << x << " ";
        cout << "\n";
    }
}