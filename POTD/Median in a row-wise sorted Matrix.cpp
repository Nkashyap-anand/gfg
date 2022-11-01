#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // R and C always odd it means always ans should be the middle one

    int search(vector<int> &nums, int low, int high, int val)
    {
        int ans = -1;
        while (low <= high)
        {
            int mid = (low + high) / 2;

            if (nums[mid] < val)
            {
                ans = mid;
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return ans + 1;
    }

    int count(int val, vector<vector<int>> &mat, int n, int m)
    {
        int ans = 0;

        for (int i = 0; i < n; i++)
        {
            ans += search(mat[i], 0, m - 1, val);
        }

        return ans;
    }

    int median(vector<vector<int>> &matrix, int R, int C)
    {
        // code here
        int low = 1, high = 2000;
        int ans_idx = (R * C) / 2;
        int ans;
        while (low <= high)
        {
            int mid = (low + high) / 2;

            int cnt = count(mid, matrix, R, C);

            if (cnt <= ans_idx)
            {
                ans = mid;
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
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
        int r, c;
        cin >> r >> c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for (int i = 0; i < r; ++i)
            for (int j = 0; j < c; ++j)
                cin >> matrix[i][j];
        Solution obj;
        cout << obj.median(matrix, r, c) << endl;
    }
    return 0;
}