#include<unordered_set>
#include<stack>
#include<iostream>
#include<vector>
#include<string>
#include<numeric>
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

bool isPalindrom(string s,ll start,ll end){
    while (start < end){
        if(s[start]!=s[end]){
            return false;
        }
        start++;
        end--;
    }
    return true;
}

void solve1(vector<vector<string>> &v,string s,ll start,vector<string> &current,ll n) {

    if(start>=n){
        v.push_back(current);
        return;
    }

    for(ll i=start;i<n;i++){
        if(isPalindrom(s,start,i)){
            current.push_back(s.substr(start,i-start+1));
            solve1(v,s,i+1,current,n);
            current.pop_back();
        }
    }
}

void solve(){
    string s;cin>>s;
    vector<vector<string>> v;
    vector<string> current;
    ll n = s.length();
    ll start = 0;
    string res = "";
    solve1(v,s,start,current,n);
    for(ll i=0;i<v.size();i++){
        for(ll j=0;j<v[i].size();j++){
            cout<<v[i][j]<<" ";
        }cout<<endl;
    }
    
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