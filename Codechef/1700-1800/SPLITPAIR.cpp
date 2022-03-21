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
    string s = to_string(n);
    ll lngth = s.length();
    ll zero = 0;
    ll odd = 0;
    ll even = 0;
    vector<ll> zeros(lngth,0);
    for(ll i=0;i<lngth;i++){
        if(s[i] == '0'){
            zeros[i]++;
            zero++;
        }
        if(stoi(s.substr(i,1))%2 == 0){
            even++;
        }
        if(stoi(s.substr(i,1))%2 == 1){
            odd++;
        }
    }
    if(stoi(s[lngth-1])%2){
        if(odd>1){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }else{
        if(stoi(s[lngth-1]) == 0){
            ll j = lngth-1;
            for(ll i=lngth-1;i>0;i--){
                if(zeros[i] == 1){
                    j = i;
                    if(lngth-j > 1){
                        cout<<"YES"<<endl;
                        return;
                    }
                }
            }
            if(lngth-j<1 &&){
                cout<<"NO"<<endl;
            }
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