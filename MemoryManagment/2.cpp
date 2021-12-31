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
 
int function(int n){
    cout<<"First"<<endl;
    return 0;
}

int function(char *ch){
    cout<<"Second"<<endl;
    return 0;
}

int f(int n,char ch){
    cout<<"hello"<<endl;
    return n;
}

int gun(int x,int (*p)(int)){
    return f(2,'l');
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    void* ptr = new bool;
    // cout<<NULL<<endl;
    *((float*)ptr) = 10.6;
    std::cout<<*((float*)ptr)<<endl;
 
    cout<<function(nullptr);
    // nullptr_t




    //Dangling Pointer
    int* p1 = new int; // p1 is in stack but address stored by it is in heap
    std::cout<<p1<<endl;
    delete p1;
    std::cout<<p1<<endl;
    p1 = NULL;
    std::cout<<p1<<endl;
    p1 = nullptr;
    std::cout<<p1<<endl;


    //Wild Pointer
    int *pwild; // it stores garbage values 

    //Function pointers
    int (*p)(int,char) = f;
    cout<<p(10,'t')<<endl;
    // cout<<gun(2,f);


    //Smart Pointers
    
    return 0;
}
