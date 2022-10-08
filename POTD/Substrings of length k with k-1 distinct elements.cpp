#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countOfSubstrings(string S, int K)
    {

        map<char, int> mp;
        int i = 0, j = 0;
        int n = S.size();
        int ans = 0;
        while (j < n)
        {
            mp[S[j]]++;
            if (j - i + 1 == K)
            {
                if (mp.size() == K - 1)
                    ans++;
                mp[S[i]]--;
                if (mp[S[i]] == 0)
                    mp.erase(S[i]);
                i++;
            }
            j++;
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
        string S;
        int K;
        cin >> S;
        cin >> K;

        Solution ob;
        cout << ob.countOfSubstrings(S, K) << endl;
    }
    return 0;
}