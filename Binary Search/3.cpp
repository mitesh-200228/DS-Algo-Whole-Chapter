//Book allocation problem
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

bool isPossible(std::vector<ll> &v,ll n,ll m,ll mid){
    ll studentCount = 1;
    ll pageSum = 0;
    for(ll i=0;i<n;i++){
        if(pageSum + v[i] <= mid){
            pageSum += v[i];
        }else{
            studentCount++;
            if(studentCount>m || mid < v[i]){
                return false;
            }
            pageSum = 0;
            pageSum += v[i];
        }   
    }
    return true;
}

void solve(){
    ll n;cin>>n;
    ll m;cin>>m;
    std::vector<ll> v(n);
    ll sum = 0;
    for(ll i=0;i<n;i++){
        cin>>v[i];
        sum+=v[i];
    }
    ll start = 0;
    ll end = sum;
    ll ans = -1;
    ll mid = start + (end-start)/2;
    while(start<=end){
        if(isPossible(v,n,m,mid)){
            ans = mid;
            end = mid - 1;
        }
        else{
            start = mid + 1;
        }
        mid = start + (end-start)/2;
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