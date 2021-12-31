#include<iostream>
#include<algorithm>
#include<queue>
#include<stack>
#include<math.h>
#include<cmath>
using namespace std;
#define ll int long long

class Node{
    public:
    ll data;
    Node* left;
    Node* right;

    Node(ll val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

ll height(Node* root){
    if(root == NULL) return 0;
    return max(height(root->left),height(root->right)) + 1;
}

bool balanced(Node* root){
    if(root == NULL) {
        return true;
    }
    if(!balanced(root->left)) return false;
    if(!balanced(root->right)) return false;
    ll lh = height(root->left);
    ll rh = height(root->right);
    if(abs(lh-rh)<=1){
        return true;
    }else{
        return false;
    }
}

int32_t main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    cout<<balanced(root);
    return 0;
}