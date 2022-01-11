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
    ll n;cin>>n;
    string s = "11";
    if(n == 1){
        cout<<"1"<<endl;
        return;
    }else if(n == 2){
        cout<<"11"<<endl;
        return;
    }else{
        for(ll i=3;i<=n;i++){
            string t = "";
            s=s+'&';
            ll cnt = 1;
            for(ll j=1;j<s.length();j++){
                if(s[j-1]==s[j]){
                    cnt++;
                }else{
                    t = t + to_string(cnt) + s[j-1];
                    cnt = 1;
                }
                cout<<t<<endl;
            }cout<<t<<endl;
            s=t;
        }   
    }
    cout<<s<<endl;
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