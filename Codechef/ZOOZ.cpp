#include <iostream>
#define ll int long long
using namespace std;

int main() {
	// your code goes here
	int long long t = 0;
	cin>>t;
	while(t--){
	    int long long n;
	    cin>>n;
        n = n-2;
        string s = "";
        for(ll i=0;i<n;i++){
            s += '0';
        }
        s = "1"+s+"1";
        cout<<s<<endl;
	}
	return 0;
}
