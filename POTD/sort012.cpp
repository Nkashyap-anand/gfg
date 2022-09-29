#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void sort012(int nums[], int n)
    {
        int l = 0, mid = 0, h = n - 1;

        while (mid <= h)
        {
            if (nums[mid] == 0)
            {
                swap(nums[l], nums[mid]);
                l++;
                mid++;
            }
            else if (nums[mid] == 1)
            {
                mid++;
            }
            else if (nums[mid] == 2)
            {
                swap(nums[mid], nums[h]);
                h--;
            }
        }
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
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        Solution ob;
        ob.sort012(a, n);

        for (int i = 0; i < n; i++)
        {
            cout << a[i] << " ";
        }

        cout << endl;
    }
    return 0;
}