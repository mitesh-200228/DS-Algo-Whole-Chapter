// https://codeforces.com/contest/1627/problem/A

#include<unordered_set>
#include<stack>
#include<iostream>
#include<vector>
#include<string>
#include<numeric>
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
 
void solve(){
    ll n,m,r,c;
    cin>>n>>m>>r>>c;
    std::vector<string> str(n);
    for(ll i=0;i<n;i++){
        cin>>str[i];   
    } 
    std::vector<vector<ll>> v(n,vector<ll> (m));
    ll cnt = 0;
    for(ll i=0;i<n;i++){
        string str1 = str[i];
        for(ll j=0;j<m;j++){
            char sp = str1[j];
            if(sp == 'W') {
                v[i][j] = 1;
            }else{
                v[i][j] = 0;
                cnt++;
            }
        }   
    }
    if(v[r-1][c-1] == 0) {
        cout<<"0"<<endl;
        return;
    }
    for(ll i=0;i<m;i++){
        if(v[r-1][i] == 0){
            cout<<"1"<<endl;
            return;
        }
    }

    for(ll i=0;i<n;i++){
        if(v[i][c-1] == 0){
            cout<<"1"<<endl;
            return;
        }
    }   
    if(cnt){
        cout<<"2"<<endl;
        return;
    }
    cout<<"-1"<<endl;

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