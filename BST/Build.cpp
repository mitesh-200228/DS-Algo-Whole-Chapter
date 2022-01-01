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
    Node* left;
    Node* right;
    Node(ll val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

Node* insertBST(Node* root,ll val){
    if(!root){
        return new Node(val);
    };
    if(val < root->data){
        root->left = insertBST(root->left,val);
    }else{
        root->right = insertBST(root->right,val);
    }
    return root;
}

void inorder(Node* root){
    if(!root) return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    Node* root = NULL;
    ll arr[] = {1,3,4,2,7};
    root = insertBST(root,5); 
    for(ll i=0;i<5;i++){
        insertBST(root,arr[i]);
    }
    inorder(root);
    return 0;
}