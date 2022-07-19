#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define v(x) vector<x>
#define vvi(x) vector<vector<x>>
#define vp(x, y) vector<pair<x, y>>
#define lb lower_bound
#define ub upper_bound
#define u_m unordered_map
#define fi first
#define se second
#define loop(i, l, r) for (int i = l; i < r; i++)
#define bn begin
#define en end
#define int long long
#define setz(x) fixed << setprecision(x)
#define print(s) cout << s << endl
#define ps(s) cout << s << ' '
const int MOD = 1e9 + 7;
int cint();
unsigned long long bint();
double cdouble();
char schar();
string gstr();
string cstr();

const int n = 1e5 + 10;

v(long double) arr(n, 0.0);

void create()
{
    loop(i, 1, n)
        arr[i] = 0.45L + 0.1L * arr[i - 1];

    loop(i, 1, n)
        arr[i] += arr[i - 1];
}

void solve()
{
    int n = cint();

    cout << setz(8) << arr[n] << '\n';
}

int32_t main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    create();
    int tc = cint();
    while (tc--)
    {
        solve();
    }

    return 0;
}

int cint()
{
    int k;
    cin >> k;
    return k;
}

double cdouble()
{
    double k;
    cin >> k;
    return k;
}

string gstr()
{
    string s;

    getline(cin, s);
    return s;
}

string cstr()
{
    string s;
    cin >> s;
    return s;
}

char schar()
{
    char c;
    cin >> c;
    return c;
}

unsigned long long bint()
{
    unsigned long long k;
    cin >> k;
    return k;
}