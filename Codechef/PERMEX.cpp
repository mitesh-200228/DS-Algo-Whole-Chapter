#include <bits/stdc++.h>
using namespace std;

void solve_Aseem()
{
    int n;
    int h = 1;
    string s;
    cin >> n >> s;
    if (s[0] == '0' || s[1] == '0' || s[n] == '0')
    {
        cout << "No\n";
        return;
    }
    vector<int> v;
    v.push_back(0);
    for (int i = 2; i < s.size() - 1; i++)
    {
        if (s[i] == '0')
            v.push_back(i);
        else
        {
            v.push_back(h);
            h = i;
        }
    }

    v.push_back(h);
    cout << "Yes\n";
    for (auto it : v)
        cout << it << " ";
    cout << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve_Aseem();
    }
}