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

class Node{
public:
    ll data;
    Node *left;
    Node *right;
    Node(ll val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};
std::unordered_map<string,ll> ump;
string solve(Node* root){
    if(!root) return "$";
    string s = "";
    if(!root->left && !root->right){
        s = to_string(root->data);
        return s;
    }
    s = s + to_string(root->data);
    s = s + solve(root->left);
    s = s + solve(root->right);
    ump[s]++;
    return s;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    Node *head = new Node(1);
    head->left = new Node(2);
    head->right = new Node(2);
    head->left->left = new Node(4);
    head->left->right = new Node(5);
    head->right->left = new Node(4);
    head->right->right = new Node(5); 
    ump.clear();
    solve(head);
    ll f = 1;
    for (auto i : ump){
        if(i.second >= 2){
            cout<<"1"<<endl;
            f = 0;
        }
    }
    if(f) cout<<"0"<<endl;
    return 0;
}