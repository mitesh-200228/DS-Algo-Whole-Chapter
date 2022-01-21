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
class Solution{
public:
    int wordBreak(string A, vector<string> &B) {
        int n=A.size();
        set<string> st;
        
        for(int i=0; i<B.size(); i++){
            st.insert(B[i]);
        }
        
        int dp[n];
        memset(dp,0,sizeof(dp));
        
        for(int i=0; i<n; i++){
            for(int j=0; j<=i; j++){
                string sub = A.substr(j,i+1-j);
                if(st.find(sub)!=st.end()){
                    if(j>0){
                        dp[i]+=dp[j-1];
                    }else{
                        dp[i]+=1;
                    }
                }
            }
        }
        
        return dp[n-1]>0;
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dict;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dict.push_back(S);
        }
        string line;
        cin>>line;
        Solution ob;
        cout<<ob.wordBreak(line, dict)<<"\n";
    }
}