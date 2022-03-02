#include<iostream>
#include<math.h>
using namespace std;


int gcd(int x,int y){
    if(y==0){
        return x;
    }
    else{
        return gcd(y,x%y);
    }
}

int main(){
    ios::sync_with_stdio(false);
    int t,n,a,ans;
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>a;
            if(i==0) ans=a;
            ans=gcd(ans,a);
        }
        if(ans!=1){
            for(int j=2;j<=sqrt(ans);j++){
                if(ans%j==0) {ans=j;break;}
            }
            cout<<ans<<endl;
        }
        else cout<<"-1"<<endl;
    }
}
