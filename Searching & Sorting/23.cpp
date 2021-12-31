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
 
// best for finding power of a^b in O(logn)
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
    ll m;cin>>m;
    vector<ll> v1(n);
    vector<ll> v2(m);
    for(ll i=0;i<n;i++){
        cin>>v1[i];
    }
    for(ll i=0; i<m ;i++){
        cin>>v2[i];
    }
    ll k;cin>>k;

    ll i = n-1;
    ll j = 0;
    while(j<m && i>=0){
        if(v1[i] > v2[j]){
            std::swap(v1[i],v2[j]);
            i--;j++;
        }else{
            i--;
            j++;
        }
    }
    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());
    if(k > n){
        k-=n;
        cout<<v2[k-1]<<endl;
    }else{
        cout<<v1[k-1]<<endl;
    }
    // for(ll i=0; i<n ;i++){
    //     cout<<v1[i]<<" ";
    // }
    // for(ll i=0; i<m ;i++){
    //     cout<<v2[i]<<" ";
    // }
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