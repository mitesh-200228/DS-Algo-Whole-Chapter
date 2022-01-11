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
    string s1,s2,res;
    cin>>s1>>s2>>res;
    ll l1 = s1.length();
    ll l2 = s2.length();
    if(s1.length() + s2.length() != res.length()){
        cout<<"NO"<<endl;
        return;
    }
    ll f=1;
    ll i=0,j=0,k=0;
    while(k<s1.length()+s2.length()){
        if(i<l1 && s1[i]==res[k]){
            i++;
        }else if(j<l2 && s2[j]==res[k]){
            j++;
        }else{
            f = 0;
            break;
        }
        k++;
    }
    if(f) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
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