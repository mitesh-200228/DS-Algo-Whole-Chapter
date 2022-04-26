#include<unordered_set>
#include<stack>
#include<iostream>
#include<vector>
#include<string>
#include<numeric>
#include<cstring>
#include<algorithm>
#include<queue>
#include <stdio.h>
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
    ll one = 0;
    ll two = 0;
    for(ll i=0;i<n;i++){
        cin>>v[i];
        if(v[i] == 1) one++;
        else if(v[i] == 2) two++;
    }
    ll ans = 0;
    vector<ll> twos(n,-1);
    vector<ll> ones(n,0);
    ll first = 0;
    if(v[n-1] == 2){
        twos[n-1] = 0;
    }
    for(ll i=n-2;i>=0;i--){
        if(v[i] < 3){
            twos[i] = twos[i+1] + 1;
        }else{
            twos[i] = twos[i+1];
        }
    }
    if(v[n-1] == 1){
        ones[n-1] = 1;
    }
    for(ll i=n-2;i>=0;i--){
        if(v[i] == 1){
            ones[i] = ones[i+1] + 1;
        }else{
            ones[i] = ones[i+1];
        }
    }
    for(auto i:ones){
        cout<<i<<" ";
    }cout<<endl;
    for(ll i=0;i<n;i++){
        if(v[i] == 1){
            ans += (n-i-1);
        }   
        else if(v[i] == 2){
            ans += twos[i];
        }else{
            ans += ones[i];
        }
    }
    cout<<ans<<endl;
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