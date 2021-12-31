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
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    std::stack<int> s;
    for(ll i=0; i<10 ;i++){
        s.push(i);   
    }

    vector<int> v {1,2,3,4,5};
    stack<int,vector<int>> st(v);
    while(!st.empty()){
        cout<<st.top()<<endl;
        st.pop();
    }    

    std::queue<int> q;
    for(ll i=0; i<5 ;i++){
        q.push(10+i);
    }
    cout<<endl;
    while(!q.empty()){
        cout<<q.front()<<" "<<q.back()<<endl;
        q.pop();
    }
    return 0;
}