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
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    ll n;cin>>n;
    vector<pair<ll,ll>> p(n);
    for(ll i=0; i<n ;i++){
        ll a,b;cin>>a>>b;
        p[i] = make_pair(a,b);   
    }
    sort(p.begin(),p.end());
    ll x = p[0].second;
    for(ll i=1; i<n ;i++){
        if(x <= p[i].second){
            x = p[i].second;
        }else{
            x = p[i].first;
        }
    }
    cout<<x<<endl;
    return 0;
}