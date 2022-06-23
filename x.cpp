#include <iostream>
#include <bits/stdc++.h>
#define ll int long long
using namespace std;

int main() {
	// your code goes here
	ll t;
	cin>>t;
	while(t--){
	    ll C;
	    cin>>C;
	    ll A=0,B=0;
        ll val = 0;
        ll dumm = C;
        while(dumm){
            val++;
            dumm /= 2;
        }
        // cout<<val<<" --";
	    ll d = ceil(log2(C));
	    bool changer = true;
	    for(ll i=0;i<val;i++){
	        if((1<<i)&C){
	            if(changer){
	                B = B|(1<<i);
	                changer = false;
	            }else{
	                A = A|(1<<i);
	                changer = true;
	            }
	        }else{
	            if((A|(1<<i)) < pow(2,d) && (B|(1<<i)) < pow(2,d)){
	                A = (A|(1<<i));
	                B = B|(1<<i);
	            }else{
	                break;
	            }
	        }
	    }
        if(A>B){
            if(((1<<0)&A) && !((1<<0)&B)){
                A = A - 1;
                B = B + 1;
            }
        }else if(B>A){
            if(((1<<0)&B) && !((1<<0)&A)){
                B = B - 1;
                A = A + 1;
            }
        }
	    cout<<A<<" "<<B<<endl;
	}
	return 0;
}
