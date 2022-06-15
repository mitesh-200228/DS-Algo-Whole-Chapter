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
std::vector<string> v;

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
 
bool isPalindrome(string s){
    ll i = 0;
    ll j = s.length() - 1;
    while(i<j){
        if(s[i]!=s[j]){
            return false;
        } 
        i++;
        j--;
    }
    return true;
}

void solve(){
    string s;cin>>s;
    ll x;cin>>x;
    string hour1 = s.substr(0,2);
    string minutes1 = s.substr(3,2);
    ll hour = stoi(hour1);
    ll minutes = stoi(minutes1);
    ll k = hour*60 + minutes;
    ll cnt = 0;
    string xo = v[k];
    ll i = k+x;
    ll n = 1440/x;
    while(n--){
        if(isPalindrome(v[i])){
            cnt++;
        }
        if(i>=v.size()-1){
            i = i%1440;
        }
        i+=x;
    }
    cout<<cnt<<endl;
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    for(ll i=0;i<24;i++){
        for(ll j=0;j<60;j++){
            string a = "",b = "";
            if(i<10){
                a = "0" + to_string(i);
            }else if(i>=10){
                a = to_string(i);
            }
            if(j<10){
                b = "0" + to_string(j);
            }else if(j>=10){
                b = to_string(j);
            }
            string final = a+b;
            // cout<<final<<" "<<endl;
            v.push_back(final);
        }
    }

    ll t;
    cin>>t;

    while(t--)
    {
        solve();
    }
    return 0;
}