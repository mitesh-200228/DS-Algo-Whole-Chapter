#include <bits/stdc++.h>
using namespace std;

#define ll int long long
class Solution
{
public:
    string secFrequent(string arr[], int n)
    {
        std::map<string, int> m;

        for (int i = 0; i < n; i++)
            m[arr[i]]++;

        auto it = m.begin();
        string firstmax = it->first;
        it++;
        string secondmax = it->first;
        it++;
        if (m[firstmax] < m[secondmax])
            swap(firstmax, secondmax);

        while (it != m.end())
        {
            if (m[firstmax] < it->second)
            {
                secondmax = firstmax;
                firstmax = it->first;
            }
            else if (m[secondmax] < it->second)
            {
                secondmax = it->first;
            }
            it++;
        }

        return secondmax;
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
        string arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        Solution ob;
        cout << ob.secFrequent(arr, n) << endl;
    }
}