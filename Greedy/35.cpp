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
 
void solve(){
    ll n;cin>>n;
    vector<ll> v1(n);
    ll sum1 = 0,sum2 = 0,sum3 = 0;
    for(ll i=0;i<n;i++){
        cin>>v1[i];
        sum1 += v1[i];   
    }
    ll m;cin>>m;
    vector<ll> v2(m);
    for(ll i=0;i<m;i++){
        cin>>v2[i];
        sum2 += v2[i];
    }
    ll p;cin>>p;
    vector<ll> v3(p);
    for(ll i=0;i<p;i++){
        cin>>v3[i];
        sum3 += v3[i];
    }
    ll x=0,y=0,z=0;
    while(x<n || y<m || z<p){
        if(sum1 == sum2 && sum2 == sum3){
            cout<<sum1<<endl;
            return;
        }
        if(sum1>=sum2 && sum1>=sum3){
            sum1 -= v1[x];
            x++;
        }
        else if(sum2>=sum1 && sum2>=sum3){
            sum2 -= v2[y];
            y++;
        }
        else if(sum3>=sum1 && sum3>=sum2){
            sum3 -= v3[z];
            z++;
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