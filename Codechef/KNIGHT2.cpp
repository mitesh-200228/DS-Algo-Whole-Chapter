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
    ll x1,y1,x2,y2;
    cin>>x1>>y1>>x2>>y2;
    ll n = 8;
    ll m = 8;
    std::vector<std::vector<ll>> matrix(8,std::vector<ll> (8,0));
    for(ll i=0;i<m;i+=2){
        ll k = 0;
        ll j = i;
        while(k<n && j<n){
            matrix[k][j] = 1;
            j++;
            k++;
        }
    }   
    for(ll i=0;i<n;i+=2){
        ll k = i;
        ll j = 0;
        while(k<n && j<n){
            matrix[k][j] = 1;
            k++;
            j++;
        }
    }
    if(matrix[x1-1][y1-1] == matrix[x2-1][y2-1]){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
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