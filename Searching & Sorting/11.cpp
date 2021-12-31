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
 
ll gcd(ll a, string b){
    ll res = 0;
    for (int i = 0; i < b.length(); i++){
        res = ((res * 10) + (b[i] - '0')) % a;
    }
    return __gcd(a,res);
}
void solve(){
    ll n;cin>>n;
    ll k;
    cin>>k;
    vector<ll> v(n);
    for(ll i=0;i<n;i++){
        cin>>v[i];
    }
    for(ll i=0; i<n ;i++){
        for(ll j=i+1;j<n;j++){
            ll l = j+1;
            ll r = n-1;
            while(l<r){
                if(v[i] + v[j] + v[l] + v[r] == k){
                    cout<<v[i]<<" "<<v[j]<<" "<<v[l]<<" "<<v[r]<<endl;
                    l++;
                    r--;
                }else if(v[i] + v[j] + v[l] + v[r] < k){
                    l++;
                }else{
                    r--;
                }
            }
        }   
    }
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