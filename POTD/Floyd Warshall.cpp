#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void shortest_distance(vector<vector<int>> &m)
    {

        int n = m.size();

        for (int k = 0; k < n; ++k)
        {
            for (int j = 0; j < n; ++j)
            {
                for (int i = 0; i < n; ++i)
                {
                    // no way to go
                    if (m[i][k] == -1 || m[k][j] == -1)
                    {
                        continue;
                    }

                    // alternate available fo no way
                    if (m[i][j] == -1)
                    {
                        m[i][j] = m[i][k] + m[k][j];
                    }

                    else
                    {
                        m[i][j] = min(m[i][j], m[i][k] + m[k][j]);
                    }
                }
            }
        }
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
        vector<vector<int>> matrix(n, vector<int>(n, -1));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> matrix[i][j];
            }
        }
        Solution obj;
        obj.shortest_distance(matrix);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << matrix[i][j] << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}