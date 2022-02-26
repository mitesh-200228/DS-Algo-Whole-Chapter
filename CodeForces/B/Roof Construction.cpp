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
 
bool isPossible(ll n,ll mid){
    for (int i = 0; i < n; i++){
        for (int j = i+1; j < n; j++){
            if((i^j) == mid) {
                return true;
                break;
            }
        }
    }
    return false;
}

void solve(){
    ll n;cin>>n;
    ll low = 1;
    ll high = n;
    ll ans = n;
    ll mid = low + (high - low) / 2;
    while (low<high){
        if(isPossible(n,mid)){
            high = mid;
            ans = mid;
        }else{
            low = mid + 1;
        }
        mid = low + (high - low)/2;
    }
    cout<<ans<<endl;
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