#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int swapBitGame(long long N)
    {
        // code here
        int cnt = 0;
        long long n = N;
        while (n > 0)
        {
            if (n & 1)
                cnt++;
            n = n >> 1;
        }

        if (cnt & 1)
            return 1;
        return 2;
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
        cout << ob.swapBitGame(N) << endl;
    }
    return 0;
}