#include <unordered_set>
#include <stack>
#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <unordered_map>
#include <set>
#include <climits>
#include <cmath>
#include <math.h>
#include <limits>

#define ll long long int
const ll N = 1e5 + 2, MOD = 1e9 + 7;
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll t;
    cin >> t;
    while (t--)
    {
        ll A, B, C;
        cin >> A >> B >> C;

        if ((A > B && A < C) || (A < B && A > C))
            cout<< A;
        else if ((B > A && B < C) || (B > C && B < A))
            cout<< B;
        if ((C > B && C < A) || (C > A && C < B))
            cout<< C;
    }

    return 0;
}