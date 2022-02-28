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
 
void solve(){
    ll n;cin>>n;
    std::vector<pair<ll,std::pair<ll,ll>>> p(n);
    for(ll i=0;i<n;i++){
        cin>>p[i].first;   
        cin>>p[i].second.first;
        cin>>p[i].second.second;
    }
    for(ll i=0;i<n;i++){
        if(p[i].first == 1){
            cout<<"YES"<<endl;
            continue;
        }else if(p[i].first == 2 && p[i-1].first == 1){
            if((p[i].second.first < p[i-1].second.first || p[i].second.first < p[i-1].second.second) || (p[i].second.second < p[i-1].second.first || p[i].second.second < p[i-1].second.second)){
                cout<<"YES"<<endl;
                continue;
            }
        }else if (p[i].second.first == p[i].second.second){
            cout<<"YES"<<endl;
            continue;   
        }
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