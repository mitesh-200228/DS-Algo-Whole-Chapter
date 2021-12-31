#include<iostream>
#include<stack>
#include<queue>
#include<algorithm>
#include<cmath>
#include<math.h>
#include<stdio.h>
#include<string>
#include<numeric>
#include<limits>
#include<climits>
#include<set>
#include<map>
#include<vector>
#include<list>
#include<unordered_map>
#include<unordered_set>
#define ll int long long
using namespace std;

ll power(ll a,ll b){
    ll temp;
    if(b == 0){
        return 1;
    }
    temp = power(a,b/2);
    if(b%2 == 0){
        return temp*temp;
    }
    return a*temp*temp;
}

void solve(){
    ll n;cin>>n;
    std::vector<ll> v(n);
    for(ll i=0;i<n;i++){
        cin>>v[i];
    }
    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}