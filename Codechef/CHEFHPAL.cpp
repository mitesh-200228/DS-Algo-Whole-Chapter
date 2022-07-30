#include <bits/stdc++.h>
#define ll long long int
#define vi vector<int>
#define a(i, s, e) for (ll i = s; i < e; i += 1)

using namespace std;

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, a;
        cin >> n >> a;
        string ans;
        ll len = 1;
        if (a == 1)
        {
            len = n;
            a(i, 0, n) ans += 'a';
        }
        else if (a == 2)
        {
            if (n < 3)
            {
                a(i, 0, n)
                {
                    if (i % 2)
                        ans += 'b';
                    else
                        ans += 'a';
                }
            }
            else if (n == 3 || n == 4)
            {
                len = 2;
                if (n == 4)
                    ans = "aabb";
                else
                    ans = "aab";
            }
            else
            {
                len = 3;
                if (n == 5)
                    ans = "aaabb";
                else if (n == 6)
                    ans = "aaabbb";
                else if (n == 7)
                    ans = "aaababb";
                else if (n == 8)
                    ans = "aaababbb";
                else
                {
                    len++;
                    vector<char> ch(6);
                    ch[0] = 'a';
                    ch[1] = 'a';
                    ch[2] = 'b';
                    ch[3] = 'b';
                    ch[4] = 'a';
                    ch[5] = 'b';
                    a(i, 0, n)
                    {
                        ans += ch[i % 6];
                    }
                }
            }
        }
        else
        {
            a(i, 0, n)
            {
                int k = i % 3;
                if (k == 0)
                    ans += 'a';
                else if (k == 1)
                    ans += 'b';
                else
                    ans += 'c';
            }
        }
        cout << len << " " << ans << endl;
    }
    return 0;
}