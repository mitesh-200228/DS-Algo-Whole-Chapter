#include<unordered_set>
#include<stack>
#include<iostream>
#include<vector>
#include<string>
#include<numeric>
#include<algorithm>
#include<queue>
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
 
void priority_queueq(std::vector<ll> &v,ll n){
    
    //-----------MAX_HEAP
    
    std::priority_queue<int> pq;
    for(ll i=0;i<n;i++){
        pq.push(i);
    }
    ll x = pq.size();
    for(ll i=0;i<x;i++){
        cout<<pq.top()<<" ";
        pq.pop();
    }cout<<endl;

    //---------MIN_HEAP
    std::priority_queue<int,vector<ll>,greater<ll> > mini;
    for(ll i=0;i<n;i++){
        mini.push(i);   
    }
    ll y = mini.size();
    for(ll i=0;i<y;i++){
        cout<<mini.top()<<" ";
        mini.pop();
    }cout<<endl;

}

void solve(){
    ll n;cin>>n;
    vector<ll> v(n);
    for(ll i=0;i<n;i++){
        cin>>v[i];
    }
    priority_queueq(v,n);
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