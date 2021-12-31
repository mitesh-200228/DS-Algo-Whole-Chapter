//Painters Partition problem
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
 
bool isPossible(std::vector<ll> &v,ll n,ll m,ll mid){
    ll numberOfPainters = 1;
    ll x = 0;
    for(ll i=0;i<n;i++){
        if(x + v[i]<=mid){
            x+=v[i];
        }else{
            numberOfPainters++;
            if(numberOfPainters <= m || mid < v[i]){
                return false;
            }
            x = v[i];
        }
    }
    return true;
}

void solve(){
    ll n;cin>>n;
    ll m;cin>>m;
    std::vector<ll> v(n);
    ll sum = 0;
    for(ll i=0;i<n;i++){
        cin>>v[i];
        sum+=v[i];
    }
    ll s = 0;
    ll e = sum;
    ll ans = -1;
    ll mid = s + (e-s)/2;
    while(s<=e){
        if(isPossible(v,n,m,mid)){
            ans = mid;
            e = mid - 1; 
        }else{
            s = mid + 1;
        }
        mid = s + (e-s)/2;
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