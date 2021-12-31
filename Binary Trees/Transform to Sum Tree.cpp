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

ll solve(Node* root){
    if(!root) return 0;
    ll a = solve(root->left);
    ll b = solve(root->right);
    ll x = root->data;
    root->data = a + b;
    return a+b+x;
}

void preorder(Node* root){
    if(!root) return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    Node* root = new Node(10);
    root->left = new Node(-2);
    root->right = new Node(6);
    root->left->left = new Node(8);
    root->left->right = new Node(-4);
    root->right->left = new Node(7);
    root->right->right = new Node(5);
    cout<<solve(root)<<endl;
    preorder(root);
    return 0;
}