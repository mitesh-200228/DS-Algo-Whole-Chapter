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
bool cmp(pair<char, ll>& a,pair<char, ll>& b){
    return a.second > b.second;
}
void solve(){
    ll n;cin>>n;
    string s;cin>>s;
    vector<pair<char,ll>> ump;
    vector<char> dp(n);
    ll count = 0;
    for(ll i=0;i<n/2;i++){
        if(s[i]!=s[n-i-1]){
            count+=2;
        }
        dp[i] = s[i];
    }
    if(count==n && n%2==0){
        cout<<"NO"<<endl;
        return;
    }else if(count==n-1 && n%2 == 1){
        cout<<"NO"<<endl;
        return;
    }
    sort(dp.begin(),dp.end());
    cout<<dp.size()<<endl;
    for(ll i=0;i<dp.size()-1;i++){   
        ll cnt = 0;
        if(dp[i]!=dp[i+1]){
            ump.push_back(make_pair(s[i],cnt+1));
            cnt = 0;
        }
    }
    sort(ump.begin(),ump.end(),cmp);
    cout<<"YES"<<endl;
    for(auto i:ump){
        cout<<i.first<<" "<<i.second<<endl;
    }
    for(auto i:ump){
        if(i.second > n/2){
            if(n%2==0){
                cout<<"NO"<<endl;
                return;
            }
        }else{
            if(i.second > n/2+1){
                if(n%2==1){
                    cout<<"NO"<<endl;return;
                }
            }
        }
        ll k = i.second;
        while(k--){
            cout<<i.first;
            // i.second--;
        }
    }cout<<endl;

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