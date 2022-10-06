#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string lexicographicallySmallest(string s, int k)
    {
        int l = s.length();
        if (!(l & (l - 1)))
            k /= 2;
        else
            k *= 2;

        if (l <= k)
            return "-1";

        stack<char> st;
        for (char ch : s)
        {
            while ((!st.empty()) && k && st.top() > ch)
            {
                st.pop();
                k--;
            }
            st.push(ch);
        }
        while (k--)
            st.pop();
        string ans = "";
        while (!st.empty())
        {
            ans = st.top() + ans;
            st.pop();
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
        int k;
        cin >> S >> k;
        Solution ob;
        cout << ob.lexicographicallySmallest(S, k) << endl;
    }
    return 0;
}