// https://www.codechef.com/LTIME104B/problems/PREZ

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
 
void solveUtil(string s,ll n,ll k){
    ll low = 0;
    ll high = 1+n;
    ll mid = low + (high - low) / 2;
    while(high-low>1){
        ll operation = 0;
        for(ll i=mid-1;i>=0;i--){
            ll req = (operation + s[i] - '0')%10;
            if(req!=0){
                operation = operation + 10 - req;
            }    
        }
        if(operation<=k){
            low = mid;
        }else{
            high = mid;
        }
        mid = low + (high - low) / 2;
    }
    cout<<low<<endl;
}

void solve(){
    ll n;cin>>n;
    ll k;cin>>k;
    string s;cin>>s;
    solveUtil(s,n,k);
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