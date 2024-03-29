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
 
ll merge(std::vector<ll> v,ll l,ll mid,ll r){
    ll inv = 0;
    ll n1 = mid - l + 1;
    ll n2 = r - mid;
    std::vector<ll> a(n1);
    std::vector<ll> b(n2);
    for(ll i=0;i<n1;i++){
        a[i] = v[l+i];
    }   
    for(ll i=0;i<n2;i++){
        b[i] = v[1+mid+i];
    }
    ll i=0;
    ll j=0;
    ll k = 0;
    while(i<n1 && j<n2){
        if(a[i]<=b[j]){
            v[k] = a[i];
            k++;
            i++;
        }else{
            v[k] = b[j];
            k++;
            j++;
            inv += n1-i;
        }
    }
    while(i<n1){
        v[k] = a[i];
        k++;
        i++;
    }
    while(j<n2){
        v[k] = b[j];
        j++;k++;
    }
    return inv;
}

ll countinvesion(std::vector<ll> v,ll l,ll r){
    ll inv = 0;
    if(l<r){
        ll mid = l + (r-l)/2;
        inv += countinvesion(v,l,mid);
        inv += countinvesion(v,mid+1,r);
        inv += merge(v,l,mid,r);
    }
    return inv;
}

void solve(){
    ll n;cin>>n;
    vector<ll> v(n);
    for(ll i=0;i<n;i++){
        cin>>v[i];
    }
    cout<<countinvesion(v,0,n-1);
    // No link Available in Question sheet, if anyone know, please create pull req with question and answer
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