//Aggressive cows
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

bool isPossible(vector<ll> &v,ll k,ll mid){
    ll cowCount = 1;
    ll lastPosition = v[0];

    for(ll i=0;i<v.size();i++){
        if(v[i] - lastPosition >= mid){
            cowCount++;
            if(cowCount == k){
                return true;
            }
            lastPosition = v[i];
        }
    }   
    return false;
}

ll aggresiveCows(std::vector<ll> &v,ll n,ll k){
    std::sort(v.begin(),v.end());
    ll s = 0;
    ll maxi = -1;
    for(ll i=0;i<v.size();i++){
        maxi = max(maxi,v[i]);
    }
    ll e = maxi;
    ll ans = -1;
    ll mid = s + (e-s)/2;
    while(s<e){
        if(isPossible(v,k,mid)){
            ans = mid;
            s = mid + 1;
        }else{
            e = mid - 1;
        }
        mid = s + (e-s)/2;
    }
}

void solve(){
    ll n;cin>>n;
    ll k;cin>>k;
    std::vector<ll> v(n);
    for(ll i=0;i<n;i++){
        cin>>v[i];
    }
    cout<<aggresiveCows(v,n,k);
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