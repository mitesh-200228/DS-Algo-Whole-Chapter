#include<bits/stdc++.h>
#define ll int long long
using namespace std;

struct Node{
    Node* left;
    Node* right;
    ll data;
    Node(ll val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

Node* insertBST(Node* root,ll val){
    if(!root){
        return new Node(val);
    }
    if(root->data > val){
        root->left = insertBST(root->left,val);
    }
    else{
        root->right = insertBST(root->right,val);
    }
    return root;
}

Node* inordeerSucc(Node* root){
    Node* curr = root;
    while(curr && !curr->left){
        curr = curr->left;
    }
    return curr;
}

Node* DeleteNodeS(Node* &root,ll k){
    if(root->data > k){
        root->left = DeleteNodeS(root->left,k);
    }
    if(root->data < k){
        root->right = DeleteNodeS(root->right,k);
    }
    else{
        if(!root->left){
            Node* temp = root->right;
            free(root);
            return temp;
        }else if(!root->right){
            Node* temp = root->left;
            free(root);
            return temp;
        }
        Node* temp = inordeerSucc(root->right);
        root->data = temp->data;
        root->right = DeleteNodeS(root->right,temp->data);
    }
    return root;
}

int32_t main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    ll k;
    cin>>k;
    Node* temp = DeleteNodeS(root,k);
    return 0;
}