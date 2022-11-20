#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long lcmTriplets(long long N)
    {
        if (N <= 2)
            return N;
        if (N % 2 == 0)
        {
            if (N % 3 == 0)
            {
                return (N - 1) * (N - 2) * (N - 3);
            }
            else
            {
                return (N - 1) * (N - 3) * (N);
            }
        }
        else
        {
            return (N - 2) * (N - 1) * (N);
        }
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long N;
        cin >> N;
        Solution ob;
        cout << ob.lcmTriplets(N) << "\n";
    }
}