#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maximizeSum(int arr[], int n)
    {
        int sum = 0;
        map<int, int, greater<int>> mp;
        for (int i = 0; i < n; i++)
        {
            mp[arr[i]]++;
        }

        while (mp.size() != 0)
        {
            auto itr = mp.begin();
            mp[itr->first]--;
            if (mp[itr->first - 1] != 0)
            {
                mp[itr->first - 1]--;
            }
            sum += itr->first;

            if (mp[itr->first - 1] == 0)
            {
                mp.erase(itr->first - 1);
            }

            if (mp[itr->first] == 0)
            {
                mp.erase(itr->first);
            }
        }
        return sum;
    }
};

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int arr[n];

        for (int i = 0; i < n; i++)
            cin >> arr[i];
        sort(arr, arr + n);
        Solution ob;

        cout << ob.maximizeSum(arr, n) << endl;
    }
}
