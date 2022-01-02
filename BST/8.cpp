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
    Node* left,*right,*next;
    Node(ll val){
        data = val;
        left = NULL;
        right = NULL;
        next = NULL;
    }
};
std::vector<ll> v;
void storeBST(Node* root){
    if(!root) return;
    storeBST(root->left);
    v.push_back(root->data);
    storeBST(root->right);
}

Node* makeTree(ll start,ll end){
    if(start > end) return NULL;
    ll mid = start + (end-start)/2;
    Node* root1 = new Node(v[mid]);

    root1->left = makeTree(start,mid-1);
    root1->right = makeTree(mid+1,end);

    return root1;
}
ll height(Node* root){
    if(!root) return 0;
    return max(height(root->left),height(root->right)) + 1;
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
    root->left = new Node(8);
    root->left->left = new Node(7);
    root->left->left->left = new Node(6);
    root->left->left->left->left = new Node(5);
    // std::vector<ll> v;
    storeBST(root);
    Node* Answer = makeTree(0,v.size()-1);
    // cout<<height(Answer);
    preorder(Answer);
    return 0;
}