#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> minPartition(int N)
    {
        vector<int> arr = {1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};
        vector<int> ans;

        for (int i = arr.size() - 1; i >= 0; i--)
        {
            if (arr[i] <= N)
            {
                int x = N / arr[i];

                for (int j = 0; j < x; j++)
                    ans.push_back(arr[i]);

                N = N % arr[i];
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
        int N;
        cin >> N;

        Solution ob;
        vector<int> numbers = ob.minPartition(N);
        for (auto u : numbers)
            cout << u << " ";
        cout << "\n";
    }
    return 0;
}