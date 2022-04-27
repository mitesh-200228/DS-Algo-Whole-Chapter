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

int second(vector<ll> v,ll l,ll h,ll x,ll n){
    while(l<=h){
        ll mid = (l) + (h-l)/2;
        if((mid == 0 || x > v[mid-1]) && v[mid] == x){
            while(x == v[mid+1]){
                mid++;
            }
            // cout<<mid<<"---";
            return mid;
        }else if(v[mid]<x){
            l=mid+1;
        }else{
            h=mid-1;
        }
    }
    return -1;
}

int first(vector<ll> v,ll l,ll h,ll x,ll n){
    while(l<=h){
        ll mid = (l) + (h-l)/2;
        if((mid == 0 || x > v[mid-1]) && v[mid] == x){
            return mid;
        }else if(v[mid]<x){
            l=mid+1;
        }else{
            h=mid-1;
        }
    }
    return -1;
}

void solve(){
    ll n;cin>>n;
    ll x;cin>>x;
    vector<ll> v(n);
    for(ll i=0;i<n;i++){
        cin>>v[i];
    }
    cout<<first(v,0,n-1,x,n)<<" ";
    cout<<second(v,0,n-1,x,n);
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