#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> satisfyEqn(int A[], int N)
    {

        unordered_map<int, pair<int, int>> m;
        vector<int> ans;

        for (int i = 0; i < N - 1; i++)
        {
            for (int j = i + 1; j < N; j++)
            {
                int sum = A[i] + A[j];

                if (m.find(sum) != m.end())
                {
                    if (m[sum].first != i && m[sum].second != i && m[sum].first != j && m[sum].second != j)
                    {
                        vector<int> v = {m[sum].first, m[sum].second, i, j};

                        if (ans.size() == 0 || ans > v)
                            ans = v;
                    }
                }

                else
                    m[sum] = {i, j};
            }
        }

        if (ans.empty())
        {
            vector<int> v = {-1, -1, -1, -1};
            return v;
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
        int A[N];

        for (int i = 0; i < N; i++)
            cin >> A[i];

        Solution ob;
        vector<int> ptr = ob.satisfyEqn(A, N);

        cout << ptr[0] << " " << ptr[1] << " " << ptr[2] << " " << ptr[3] << endl;
    }
    return 0;
}