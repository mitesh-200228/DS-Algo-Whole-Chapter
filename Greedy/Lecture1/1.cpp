/*
    Given an array of even length of natural numbers.
    2 Players A and B play and A starts first. after that
    they change turns. Every turns the player can pick a no 
    from the end of the array . Decide a statergy so that Player A never loose
*/

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
 
// best for finding power of a^b in O(logn)
int power(ll a,ll b) {
    ll N = 1;
    while(b>0){
        if(b%2){
            N=N*a;
        }
        a=a*a;b>>=1;
    }
    return N;
}
 
ll gcd(ll a, string b){
    ll res = 0;
    for (int i = 0; i < b.length(); i++){
        res = ((res * 10) + (b[i] - '0')) % a;
    }
    return __gcd(a,res);
}
void solve(){
    ll n;cin>>n;
    vector<ll> v(n);
    ll i = 0;
    for(i=0;i<n;i++){
        cin>>v[i];
    }
    i = 0;
    ll j = n-1;
    ll A = 0;
    ll B = 0;
    ll N = n;
    while(i<j){
        if((v[i]<v[j]) && N%2==0){
            A+=v[j];
            j--;
            N--;
        }else if((v[i]>v[j]) && N%2==0){
            A+=v[i];
            i++;
            N--;
        }else if((v[i]>v[j]) && N%2!=0){
            B+=v[i];
            i++;
            N--;
        }else if((v[i]<v[j]) && N%2!=0){
            B+=v[j];
            j--;
            N--;
        }
        
    }
        cout<<A<<" "<<B<<endl;


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