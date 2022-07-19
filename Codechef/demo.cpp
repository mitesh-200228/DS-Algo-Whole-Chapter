// PCYCLE
#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e5 + 5;
const int MOD = 1e9 + 7;

int main ()
{
    ios_base :: sync_with_stdio (false);
    cin.tie (NULL);
    cout.tie (NULL);

    short n, i, j;
    cin >> n;

    vector <short> v(n), w(n+1, 0);

    for (auto &x : v) cin >> x;

    map<int, vector<int>> m;

    for (i = 0; i < n; i++)
    {
        j = (i + 1);

        while (w[j] == 0)
        {
            w[j] = 1;
            m[i+1].push_back(j);
            j = v[j-1];
        }
    }

    cout << m.size() << "\n";

    for (auto it : m)
    {
        for (i = 0; i < it.second.size(); i++)
        {
            cout << it.second[i] << " ";
        }
        cout << it.first << "\n";
    }

    return 0;
}