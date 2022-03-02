#include<bits/stdc++.h>
#define ll int long long
using namespace std;

ll v[1010][1010];

void solve(){
    for(int i=1;i<1010;i++){
        v[i][1] = i*(i+1)/2;
        for(int j=2;j<1010;j++){
            v[i][j] = v[i][j-1] + (i-1) + ( j-1 );
        }
    }    
}

int main()
{
    solve();   
    ll t; cin>>t;
    while(t--){
        ll x1, y1, x2, y2;cin>>x1>>y1>>x2>>y2;
        ll sum = 0;
        for(int i=x1;i<=x2;i++){
            sum += v[i][y1];
        }
        for(int j=y1+1;j<=y2;j++){
            sum += v[x2][j];
        }
        cout<<sum<<endl;
    }
}