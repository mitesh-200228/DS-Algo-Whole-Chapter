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
 
void print(vector<ll> v,ll n){
    for(ll i=0;i<n;i++){
        cout<<v[i]<<' ';
    }cout<<endl;
}

ll powee(ll n){
    ll ans = 0;
    for (int i = n; i >= 1; i--){
        if(!(i&(i-1))){
            ans = i;
            break;
        }
    }
    return ans;
}

void solve(){
    ll n;cin>>n;
    vector<ll> v(n+1);
    for(ll i=0;i<n+1;i++){
        cin>>v[i];
    }
    vector<ll> ans(3,0);
    for(ll i=powee(n);i>0;i/=2){
        ll x = v[i]-v[0];
        if(x<0){
            x=x*(-1);
            ll cnt = x/i;
            if(cnt==1){
                cnt=2;
                if((ans[0]^i)<=n){
                    ans[0]^=i;
                    cnt--;
                }
                if(cnt && (ans[1]^i)<=n){
                    ans[1]^=i;
                    cnt--;
                }
                if(cnt>=1 && (ans[2]^i)<=n){
                    ans[2]^=i;
                }
            }
            else if(cnt==3){
                ans[0]^=i;
                ans[1]^=i;
                ans[2]^=i;
            }
        }else{
            ll cnt = x/i;
            if(cnt == 1){
                if((ans[0]^i)<=n){
                    ans[0]^=i;
                }else if((ans[1]^i)<=n){
                    ans[1]^=i;
                }else{
                    ans[2]^=i;
                }
            }
        }
        std::sort(ans.begin(),ans.end());
    }
    cout<<ans[0]<<" "<<ans[1]<<" "<<ans[2]<<endl;
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