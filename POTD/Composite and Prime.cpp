#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    bool isprime(int n)
    {
        for (int i = 2; i <= sqrt(n); i++)
        {
            if (n % i == 0)
            {
                return false;
            }
        }
        return true;
    }
    int Count(int L, int R)
    {

        int p = 0;
        int c = 0;
        for (int i = L; i <= R; i++)
        {
            if (i == 1)
                continue;
            else if (isprime(i) == 1)
                p++;
            else
                c++;
        }
        return c - p;
    }
};

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int L, R;
        cin >> L >> R;
        Solution obj;
        int ans = obj.Count(L, R);
        cout << ans << "\n";
    }
    return 0;
}