#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string ReFormatString(string S, int K)
    {
        string ans = "";
        string tmp = "";
        ;
        for (int i = S.size() - 1; i >= 0; i--)
        {
            if (S[i] == '-')
                continue;
            else if ('0' <= S[i] and S[i] <= '9' || isupper(S[i]))
                tmp += S[i];
            else
                tmp += toupper(S[i]);
            if (tmp.size() == K)
                ans += tmp + '-', tmp = "";
        }
        if (tmp.size())
            ans += tmp;
        reverse(begin(ans), end(ans));
        if (ans[0] == '-')
            return ans.substr(1, ans.size());
        return ans;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S;
        cin >> S;
        int K;
        cin >> K;
        Solution ob;
        string ans = ob.ReFormatString(S, K);
        cout << ans;
        cout << "\n";
    }
    return 0;
}