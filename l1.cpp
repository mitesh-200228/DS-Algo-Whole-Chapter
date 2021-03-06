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
 
ll binary_search_for_left(std::vector<ll> v,ll l,ll n){
    ll i = 0;
    ll j = n;
    ll mid = i + (j-i)/2;
    while(i<j){
        if(v[mid] == l){
            i = mid + 1;
        }else if(v[mid] < l){
            i = mid + 1;
        }else{
            j = mid - 1;
        }
        mid = i + (j-i)/2;
    }
    return mid;
}

ll binary_search_for_right(std::vector<ll> v,ll l,ll n){
    ll i = 0;
    ll j = n;
    ll mid = i + (j-i)/2;
    while(i<j){
        // cout<<mid<<" -- "<<endl;
        if(v[mid] == l){
            j = mid - 1;
        }else if(v[mid] < l){
            i = mid + 1;
        }else{
            j = mid - 1;
        }
        mid = i + (j-i)/2;
    }
    return mid;
}

void solve(){
    ll n;cin>>n;
    std::vector<ll> v(n);
    for(ll i=0;i<n;i++){
        cin>>v[i];   
    }
    ll k;cin>>k;
    std::sort(v.begin(),v.end());
    while(k--){
        ll l,r;cin>>l>>r;
        ll x = binary_search_for_left(v,l,n);
        ll y = binary_search_for_right(v,r,n);
        cout<<x<<" "<<y<<endl;
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