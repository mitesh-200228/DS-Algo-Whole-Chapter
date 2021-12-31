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

bool isValid(char c){
    return ((c == '(') || (c == ')'));
}

bool isValidString(string str){
    ll cnt = 0;
    for(ll i=0; i<str.length();i++){
        if(str[i] == '('){
            cnt++;
        }else if(str[i] == ')'){
            cnt--;
        }
    }
    return (cnt == 0);
}



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    return 0;
}