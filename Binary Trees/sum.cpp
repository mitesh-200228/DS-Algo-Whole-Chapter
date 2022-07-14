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

void preorder(Node* root){
    if(!root) return;
    preorder(root->left);
    cout<<root->data<<" ";
    preorder(root->right);
}

void sum(Node* &root){
    if(!root) return;
    if(root->left == NULL && root->right == NULL){
        root->data = 0;
    }else{
        root->data = root->left->data + root->right->data; 
    }
    sum(root->left);
    sum(root->right);
}

int32_t main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    // sum(root);
    preorder(root);
    return 0;
}