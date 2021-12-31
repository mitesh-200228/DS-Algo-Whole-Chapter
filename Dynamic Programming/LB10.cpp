#include<unordered_set>
#include<stack>
#include<iostream>
#include<vector>
#include<string>
#include<numeric>
#include<algorithm>
#include<queue>
#include<stack>
#include<map>
#include<unordered_map>
#include<set>
#include<climits>
#include<cmath>
#include<math.h>
#include<limits>
#define ll long long int
const ll N = 1e5+ 2,MOD = 1e9+7;
using namespace std;
int power(ll a,ll b) {
    ll ans = 1;
    while(b>0){
        if(b%2){
            ans=ans*a;
        }
        a=a*a;b>>=1;
    }
    return ans;
}
ll countSetBits(ll n) {
    ll count = 0;
    while (n)
    {
        count += n & 1;
        n >>= 1;
    }
    return count;
}
 
ll gcd(ll a, string b){
    ll res = 0;
    for (int i = 0; i < b.length(); i++){
        res = ((res * 10) + (b[i] - '0')) % a;
    }
    return __gcd(a,res);
}
 
void solve(){
    ll n,m;
    std::cin>>n>>m;
    ll a[][4] = {{4,5,3,2},{2,10,1,4}};
    ll t[][4] = {{0,7,4,5},{0,9,2,8}};
    ll e[] = {10,12};
    ll x[2] = {18,7};

    ll T1[4],T2[4],i;
    T1[0] = e[0] + a[0][0];
    T2[0] = e[1] + a[1][0];

    for(ll i=1;i<n;i++){
        T1[i] = min(T1[i-1] + a[0][i],T2[i-1] + t[1][i] + a[0][i]);
        T2[i] = min(T2[i-1] + a[1][i],T1[i-1] + t[0][i] + a[1][i]);
    }

    cout<<min(T1[3] + x[0] , T2[3] + x[1]);

}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    ll t;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}