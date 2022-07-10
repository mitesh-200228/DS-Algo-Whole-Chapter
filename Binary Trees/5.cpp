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
    int data;
    Node* left;
    Node* right;

    Node(ll val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

void preorder(Node* &head){
    if(head == NULL){
        return;
    }

    cout<<head->data<<" ";
    preorder(head->left);
    preorder(head->right);
}

void inorder(Node* &head){
    if(head == NULL){
        return;
    }

    inorder(head->left);
    cout<<head->data<<" ";
    inorder(head->right);
}

void postorder(Node* &head){
    if(head == NULL){
        return;
    }

    postorder(head->left);
    postorder(head->right);
    cout<<head->data<<" ";
}

void Mirror(Node* root){
    if(!root){
        return;
    }
    Mirror(root->left);
    Mirror(root->right);
    if(root->left){
        Node* n = root->right;
        root->right = root->left;
        root->left = n;
    }
    else if(root->right){
        Node* m = root->right;
        root->left = root->right;
        root->right = m;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    Node* head = new Node(1);
    head->left = new Node(2);
    head->right = new Node(3);
    head->left->left = new Node(4);
    head->left->right = new Node(5);
    head->right->left = new Node(6);
    head->right->right = new Node(7);
    // postorder(head);
    preorder(head);
    cout<<"\n";
    Mirror(head);
    preorder(head);
    return 0;
}