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
 
// void heapify(std::vector<ll> &v,ll n,ll i){
//     ll maxIdx = i;
//     ll l = 2*i+1;
//     ll r = 2*i+2;

//     if(l<n && v[l]>v[maxIdx]){
//         maxIdx = l;
//     }
//     if(r<n && v[r]>v[maxIdx]){
//         maxIdx = r;
//     }
//     if(maxIdx != i){
//         swap(v[i],v[maxIdx]);
//         heapify(v,n,maxIdx);
//     }
// }
// /*   4
//     / \
//    5   3
//   / \ / 
//  2  6 1
// */  
// void heapsort(std::vector<ll> &v){
//     ll n = v.size();
//     for(ll i=n/2 - 1;i>=0;i--){
//         heapify(v,n,i);
//     }
//     for(ll i=n-1;i>0;i--){
//         swap(v[0],v[i]);
//         heapify(v,i,0);
//     }
// }

void heapify(std::vector<ll> &v,ll n,ll i){
    ll maxSiz = i;
    ll l = 2*i + 1;
    ll r = 2*i + 2;
    if(l<n && v[l]>v[maxSiz]){
        maxSiz = l;
    }
    if(r<n && v[r]>v[maxSiz]){
        maxSiz = r;
    }
    if(i!=maxSiz){
        swap(v[i],v[maxSiz]);
        heapify(v,n,maxSiz);
    }
}

void heapsort(std::vector<ll> &v){
    ll n = v.size();
    // For max Heap
    for(ll i=(n/2) - 1;i>=0;i--){
        heapify(v,n,i);
    }
    // For Heap Sort
    for(ll i=n-1;i>0;i--){
        swap(v[0],v[i]);
        heapify(v,i,0);
    }
}

void solve(){
    ll n;cin>>n;
    vector<ll> v(n);
    for(ll i=0;i<n;i++){
        cin>>v[i];
    }
    heapsort(v);
    print(v,n);
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