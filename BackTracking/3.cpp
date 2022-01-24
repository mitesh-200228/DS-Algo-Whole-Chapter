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

int dictonary(string &word){
    string dictonary[] = {"mobile","samsung","sam","sung","man","mango", "icecream","and","go","i","love","ice","cream"};
    ll n = sizeof(dictonary)/sizeof(dictonary[0]);
    for(ll i=0;i<n;i++){
        if(dictonary[i].compare(word) == 0){
            return true;
        }
    }  
    return false;
}

void wordBreak(string s,ll n,string result){
    for(ll i=0;i<n;i++){
        string substr = s.substr(0,i);
        if(dictonary(substr)){
            if(i == n){
                result = result + substr;
                cout<<result<<endl;
                return;
            }
            wordBreak(s.substr(i,n-i),n-i,result+substr+" ");
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string s = "iloveicecreamandmango";
    string result = "";
    ll n = s.length();
    // cout<<n<<endl;s
    wordBreak(s,n,result);
    return 0;
}