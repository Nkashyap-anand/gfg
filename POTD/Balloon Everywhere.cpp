#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxInstance(string s)
    {

        map<char, int> mp;

        for (auto &it : s)

            mp[it]++;

        int ans = min({mp['b'], mp['a'], mp['l'] / 2, mp['o'] / 2, mp['n']});

        return ans;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.maxInstance(s) << endl;
    }
    return 0;
}
