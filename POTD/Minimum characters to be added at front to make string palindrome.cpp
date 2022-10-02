#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minChar(string str)
    {

        int l = 0, r = str.length() - 1, count = 0;

        while (l < r)
        {
            if (str[l] == str[r])
            {
                l++;
                r--;
            }
            else
            {
                count++;
                l = 0;
                r = str.length() - 1 - count;
            }
        }
        return count;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string str;
        cin >> str;
        Solution ob;
        int ans = ob.minChar(str);
        cout << ans << endl;
    }
    return 0;
}