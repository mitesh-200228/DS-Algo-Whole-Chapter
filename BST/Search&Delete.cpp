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

Node* searchInBST(Node* root,ll key){
    if(!root) return NULL;
    if(root->data == key){
        return root;
    }
    if(root->data > key){
        return searchInBST(root->left,key);
    }
    return searchInBST(root->right,key);
}

Node* inorderSucc(Node* root){
    Node* curr = root;
    while(curr && curr->left!=NULL){
        curr = curr->left;
    }
    return curr;
}

Node* deletenode(Node* root,ll key){
    if(key < root->data){
        root->left = deletenode(root->left,key);
    }
    else if(key > root->data){
        root->right = deletenode(root->right,key);
    }
    else{
        if(root->left == NULL){
            Node* temp = root->right;
            free(root);
            return temp;
        }else if(root->right == NULL){
            Node* temp = root->left;
            free(root);
            return temp;
        }
        Node* temp = inorderSucc(root->right);
        root->data = temp->data;
        root->right = deletenode(root->right,temp->data);
    }
    return root;
}

void inorder(Node* root){
    if(!root) return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
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
    Node* Answer = searchInBST(root,3);
    if(Answer) cout<<"1"<<endl;
    else{
        cout<<"0"<<endl;
    }
    inorder(root);cout<<endl;
    root = deletenode(root,3);
    inorder(root);
    return 0;
}