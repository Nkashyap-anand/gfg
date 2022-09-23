#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minLength(string s, int n)
    {

        set<string> setp = {"12", "21", "34", "43", "56", "65", "78", "87", "09", "90"};

        stack<char> st;

        for (auto it : s)

        {
            string cnew;

            if (st.empty())
                st.push(it);

            else

            {
                cnew.push_back(st.top());

                cnew.push_back(it);

                if (setp.find(cnew) != setp.end())

                {
                    n -= 2;

                    st.pop();
                }
                else
                    st.push(it);
            }
        }
        return n;
    }
};

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        string s;
        cin >> s;

        Solution obj;
        cout << obj.minLength(s, n) << "\n";
    }
    return 0;
}