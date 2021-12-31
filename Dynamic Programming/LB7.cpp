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
    ll n;cin>>n;
    vector<ll> v(n);
    for(ll i=0;i<n;i++){
        cin>>v[i];
    }

    ll sum = 0;
    for(ll i=0;i<n;i++){
        sum += v[i];   
    }
    if(sum%2 != 0){
        cout<<false<<endl;
        return;
    }
    bool part[sum/2 + 1][1+n];

    for(ll i=0;i<=n;i++){
        part[0][i] = true;
    }
    for(ll j=0;j<n;j++){
        part[j][0] = false;
    }
    for(ll i=1;i<=sum/2;i++){
        for(ll j=1;j<=n;j++){
            part[i][j] = part[i][j-1];
            if(i>=v[j-1]){
                part[i][j] = part[i][j] || part[i-v[j-1]][j-1];
            }
        }
    }

    // uncomment this part to print table
    for (ll i = 0; i <= sum/2; i++){
        for (ll j = 0; j <= n; j++){
            cout<<part[i][j]<<" ";
        }
        cout<<endl;
    } 
 
    cout<<part[sum / 2][n]<<endl;
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