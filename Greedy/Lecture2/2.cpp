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
    
    ll n;
    cin>>n;

    vector<pair<ll,ll>> p;
    for(ll i=0; i<n ;i++){
        ll s,e;
        cin>>s>>e;
        p.push_back(make_pair(s,e));   

        sort(p.begin(),p.end());
        ll count = 1;
        pair<ll,ll> last = p[0];

        for(ll i=1;i<n;i++){
            if(p[i].first >= last.second){
                count++;
                last = p[i];
            }
        }
        cout<<count<<endl;
    }

    return 0;
}