#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    pair<int, int> endPoints(vector<vector<int>> matrix, int R, int C)
    {

        vector<pair<int, int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int row = matrix.size(), col = matrix[0].size();

        int i = 0, j = 0, k = 0;
        pair<int, int> ans;

        while (i >= 0 && j >= 0 && i < row && j < col)
        {
            ans = {i, j};

            if (matrix[i][j] == 1)
            {
                matrix[i][j] = 0;
                k = (k + 1) % 4;
            }

            i = i + dir[k].first;
            j = j + dir[k].second;
        }
        return ans;
    }
};

int main()
{
    int tc;
    scanf("%d", &tc);
    while (tc--)
    {
        int row, col;
        scanf("%d", &row);
        scanf("%d", &col);
        vector<vector<int>> matrix(row, vector<int>(col));

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                cin >> matrix[i][j];
            }
        }
        Solution obj;
        pair<int, int> p = obj.endPoints(matrix, row, col);

        cout << "(" << p.first << ", " << p.second << ")" << endl;
    }
    return 0;
}