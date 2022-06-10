#include<unordered_set>
#include<stack>
#include<iostream>
#include<vector>
#include<string>
#include<numeric>
#include<cstring>
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
#define n 100
using namespace std;

class Stack{
    int* arr;
    int top;
    
    public:
    stack(){
        arr=new int[n];
        top=-1;
    }

    void push(int x){
        if(top==n-1){
            cout<<"Stack Overflow"<<endl;
            return;
        }
        arr[++top] = x;
    }

    void pop(){
        if(top==-1){
            cout<<"Stack UnderFlow"<<endl;
            return;
        }
        top--;
    }

    int Top(){
        if(top==-1){
            cout<<"Stack Empty"<<endl;
            return -1;
        }
        return arr[top];
    }

    bool isEmpty(){
        if(top==-1){
            cout<<"Stack is Empty"<<endl;
            return true;
        }
        return false;
    }
}; 

 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    Stack st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    cout<<st.Top();
    st.pop();
    cout<<st.Top();
    return 0;
}