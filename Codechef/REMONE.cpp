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

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;
    while(T--){
        int N; cin >> N;
        unordered_set<int> s;
        vector<ll> A(N);
        for(auto &i : A) cin >> i, s.insert(i);
        vector<ll> B(N-1); 
        for(auto &i : B) cin >> i;
    
        sort(A.begin(),A.end()); 
        sort(B.begin(),B.end());

        int ans = B[0]-A[1];
        for(auto i : B){
            if(s.count(i-ans) == 0){
                ans = B[0]-A[0];
                break;
            }
        }

        if(ans <= 0) ans = B[0]-A[0];
        cout << ans << "\n";
    }

    return 0;
}