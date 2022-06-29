// #include<unordered_set>
// #include<stack>
// #include<iostream>
// #include<vector>
// #include<string>
// #include<numeric>
// #include<cstring>
// #include<algorithm>
// #include<queue>
// #include <stdio.h>
// #include<stack>
// #include<map>
// #include<unordered_map>
// #include<set>
// #include<climits>
// #include<cmath>
// #include<math.h>
// #include<limits>
// #define ll long long int
// const ll N = 1e5+ 2,MOD = 1e9+7;
// using namespace std;
// int power(ll a,ll b) {
//     ll ans = 1;
//     while(b>0){
//         if(b%2){
//             ans=ans*a;
//         }
//         a=a*a;b>>=1;
//     }
//     return ans;
// }
// ll countSetBits(ll n) {
//     ll count = 0;
//     while (n)
//     {
//         count += n & 1;
//         n >>= 1;
//     }
//     return count;
// }

// ll gcd(ll a, string b){
//     ll res = 0;
//     for (int i = 0; i < b.length(); i++){
//         res = ((res * 10) + (b[i] - '0')) % a;
//     }
//     return __gcd(a,res);
// }

// void print(vector<ll> v,ll n){
//     for(ll i=0;i<n;i++){
//         cout<<v[i]<<' ';
//     }cout<<endl;
// }

// void solve(){
//     ll n;cin>>n;
//     vector<ll> v(n);
//     for(ll i=0;i<n;i++){
//         cin>>v[i];
//     }
//     vector<ll> prefix(n,0);
//     prefix[0] = v[0];
//     for(ll i=1;i<n;i++){
//         prefix[i] = v[i]^prefix[i-1];
//     }
//     for(ll i=0;i<n;i++){
//         if(i!=0 && i!=n-1){
//             if(prefix[i-1]^prefix[i+1] == v[i]){
//                 cout<<v[i]<<endl;
//                 return;
//             }
//         }else if(i==0){
//             if(v[i] == prefix[1]){
//                 cout<<v[i]<<endl;
//                 return;
//             }
//         }else if(i==n-1){
//             if(v[i] == prefix[n-2]){
//                 cout<<v[i]<<endl;
//                 return;
//             }
//         }
//     }
// }

// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);

//     ll t;
//     cin>>t;
//     while(t--)
//     {
//         solve();
//     }
//     return 0;
// }

// #include<unordered_set>
// #include<stack>
// #include<iostream>
// #include<vector>
// #include<string>
// #include<numeric>
// #include<cstring>
// #include<algorithm>
// #include<queue>
// #include <stdio.h>
// #include<stack>
// #include<map>
// #include<unordered_map>
// #include<set>
// #include<climits>
// #include<cmath>
// #include<math.h>
// #include<limits>
// #define ll long long int
// const ll N = 1e5+ 2,MOD = 1e9+7;
// using namespace std;
// int power(ll a,ll b) {
//     ll ans = 1;
//     while(b>0){
//         if(b%2){
//             ans=ans*a;
//         }
//         a=a*a;b>>=1;
//     }
//     return ans;
// }
// ll countSetBits(ll n) {
//     ll count = 0;
//     while (n)
//     {
//         count += n & 1;
//         n >>= 1;
//     }
//     return count;
// }

// ll gcd(ll a, string b){
//     ll res = 0;
//     for (int i = 0; i < b.length(); i++){
//         res = ((res * 10) + (b[i] - '0')) % a;
//     }
//     return __gcd(a,res);
// }

// void print(vector<ll> v,ll n){
//     for(ll i=0;i<n;i++){
//         cout<<v[i]<<' ';
//     }cout<<endl;
// }

// void solve(){
//     ll n;cin>>n;
//     ll k;cin>>k;
//     vector<ll> v(n);
//     for(ll i=0;i<n;i++){
//         cin>>v[i];
//     }
//     if(k==1){
//         cout<<(n-1)/2<<endl;
//         return;
//     }else{
//         ll cnt= 0;
//         for(ll i=0;i<n;i++){
//             if(i!=0 && i!=n-1){
//                 if(v[i]>v[i-1]+v[i+1]){
//                     cnt++;
//                 }
//             }
//         }
//         cout<<cnt<<endl;
//     }
// }

// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);

//     ll t;
//     cin>>t;
//     while(t--)
//     {
//         solve();
//     }
//     return 0;
// }

#include <unordered_set>
#include <stack>
#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include <cstring>
#include <algorithm>
#include <queue>
#include <stdio.h>
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
int power(ll a, ll b)
{
    ll ans = 1;
    while (b > 0)
    {
        if (b % 2)
        {
            ans = ans * a;
        }
        a = a * a;
        b >>= 1;
    }
    return ans;
}
ll countSetBits(ll n)
{
    ll count = 0;
    while (n)
    {
        count += n & 1;
        n >>= 1;
    }
    return count;
}

ll gcd(ll a, string b)
{
    ll res = 0;
    for (int i = 0; i < b.length(); i++)
    {
        res = ((res * 10) + (b[i] - '0')) % a;
    }
    return __gcd(a, res);
}

void print(vector<ll> v, ll n)
{
    for (ll i = 0; i < n; i++)
    {
        cout << v[i] << ' ';
    }
    cout << endl;
}

void solve()
{
    ll n;
    cin >> n;
    vector<ll> v(n);
    ll zero = false;
    std::map<ll, ll> ump;
    vector<ll> newV;
    ll z = 0;
    for (ll i = 0; i < n; i++){
        cin >> v[i];
        if (v[i] != 0)
            zero = true;
        else
            ++z;
        ump[v[i]]++;
        if (ump[v[i]] <= 3){
            newV.push_back(v[i]);
        }
    }
    if (!zero){
        cout << "YES" << endl;
        return;
    }
    std::sort(newV.begin(), newV.end());
    if (z == n - 2 && newV[0] == -1 * newV.back()){
        cout << "YES" << endl;
        return;
    }
    if (newV.size() > 10){
        cout << "NO" << endl;
        return;
    }
    else{
        ll sz = newV.size();
        bool nope = true;
        for (ll i = 0; i < sz; ++i){
            for (ll j = i + 1; j < sz; ++j){
                for (ll k = j + 1; k < sz; ++k){
                    if (ump.count(newV[i] + newV[j] + newV[k]) == 0){
                        nope = false;
                    }
                }
            }
        }
        if (nope){
            cout << "YES" << endl;
        }
        else
            cout << "NO" << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}