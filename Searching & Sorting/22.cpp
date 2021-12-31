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
ll solve(){
    ll n;cin>>n;
    vector<ll> a(n);
    for(ll i=0;i<n;i++){
        cin>>a[i];
    }
    if(n == 0) return 0;
    if(a[0]<=a[n-1]) return 0;

    ll l = 0;
    ll r = n - 1;

    while(l<=r){
        ll mid = l + (r-l)/2;
        if(a[mid]>a[mid+1]){
            return mid+1;
        }else if(a[l]<=a[mid]){
            l = mid+1;
        }else{
            r = mid-1;
        }
    }
    return -1;
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
        ll z = solve();
        cout<<z<<endl;
    }
    return 0;
}