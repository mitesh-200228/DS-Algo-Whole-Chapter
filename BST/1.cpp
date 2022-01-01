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

struct Node{
    ll data;
    Node* left,*right;
    Node(ll val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

Node* insertion(Node* root,ll key){
    if(!root) return new Node(key);
    if(key > root->data){
        root->right = insertion(root->right,key);
    }
    else if(key < root->data){
        root->left = insertion(root->left,key);
    }
    return root;
}

void inorder(Node* root){
    if(!root) return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

Node* searching(Node* root,ll key){
    if(!root) return NULL;
    if(key == root->data) return root;
    if(key> root->data) return searching(root->right,key);
    if(key< root->data) return searching(root->left,key);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    Node* root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(5);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right->right = new Node(6);
    ll key = 10;
    Node* temp = insertion(root,key);
    inorder(temp);
    cout<<endl;
    if(searching(root,42) == NULL){
        cout<<"0"<<endl;
    }else cout<<"1"<<endl;
    return 0;
}