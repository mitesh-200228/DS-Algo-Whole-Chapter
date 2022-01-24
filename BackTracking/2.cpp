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

bool isSafe(std::vector<vector<ll>> &v,ll x,ll y,ll n){
    if(x<n && y<n){
        for(ll row=0;row<x;row++){
            if(v[row][y] == 1){
                return false;
            }
        }
        ll row = x;
        ll column = y;
        while(row>=0 && column>=0){
            if(v[row][column] == 1){
                return false;
            }
            row--;
            column--;
        }
        row=x;
        column = y;
        while(row>=0 && column<=n){
            if(v[row][column] == 1){
                return false;
            }
            row--;
            column++;
        }
        return true;
    }
    return false;
}

bool nQueen(std::vector<vector<ll>> &v,ll x,ll n){
    if(x>=n){
        return true;
    }
    for(ll col=0;col<n;col++){
        if(isSafe(v,x,col,n)){
            v[x][col] = 1;
            if(nQueen(v,x+1,n)){
                return true;
            }
            v[x][col] = 0;
        }
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n;cin>>n;
    vector<vector<ll>> v(n,vector<ll>(n,0));
    if(nQueen(v,0,n)){
        for(ll i=0;i<n;i++){
            for(ll j=0;j<n;j++){
                cout<<v[i][j]<<" ";
            }cout<<endl;
        }
    }
    return 0;
}