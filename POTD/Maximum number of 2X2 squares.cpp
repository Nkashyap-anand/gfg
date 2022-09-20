#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long int numberOfSquares(long long int base)
    {
        long long int b = 0, a = 0;

        b = (base - 2) / 2;

        // on every base, (base_size-2) square can accumulate;

        a = (b * (b + 1)) / 2;

        // we have to take sum of first b natural number as it will reduce by one each time;

        return a;
    }
};

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        long long int base;
        cin >> base;

        Solution ob;
        cout << ob.numberOfSquares(base) << "\n";
    }

    return 0;
}
