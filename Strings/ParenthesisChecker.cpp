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
 
bool solve1(){
    string s;cin>>s;
    std::stack<char> stacks;
    char a;
    ll n = s.length();
    for(ll i=0;i<n;i++){
        if(s[i] == '(' || s[i] == '{' || s[i] == '['){
            stacks.push(s[i]);
            continue;
        }
        if(stacks.empty()){
            return false;
        }
        switch (s[i]){
            case ')':
                a=stacks.top();
                stacks.pop();
                if(a=='{' || a=='['){
                    return false;
                }
                break;
            case ']':
                a=stacks.top();
                stacks.pop();
                if(a=='(' || a=='{'){
                    return false;
                }
                break;
            case '}':
                a=stacks.top();
                stacks.pop();
                if(a=='(' || a=='['){
                    return false;
                }
                break;
        }
    }
    return (s.empty());
}

void solve(){
    bool x = solve1();
    cout<<x;
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