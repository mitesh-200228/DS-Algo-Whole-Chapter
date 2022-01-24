#include <iostream>
#include <string>

#define ll int long long
#define R 3
#define C 3
using namespace std;

void solve1(string arr[R][C],ll m,ll n,string output[R]) {
    output[m] = arr[m][n];
    if(m == R-1){
        for(ll i=0;i<R;i++){
            cout<<output[i]<<" ";
        }cout<<endl;
        return;
    }

    for(ll i=0;i<C;i++){
        if(arr[m+1][i]!=""){
            solve1(arr,m+1,i,output);
        }
    }
}

void solve(string arr[R][C]){
    string output[R];
    for(ll i=0;i<R;i++){
        if(arr[0][i] != ""){
            solve1(arr,0,i,output);
        }
    }
}

int main()
{
    string arr[R][C] = {{"you", "we"},{"have", "are"},{"sleep", "eat", "drink"}};
    solve(arr);
    return 0;
}
