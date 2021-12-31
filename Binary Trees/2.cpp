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

ll position(ll inorder[],ll curr,ll start,ll end){
    for(ll i=start;i<=end;i++){
        if(inorder[i] == curr) return i;
    }
    return -1;
}

void inorderPrint(Node* &root){
    if(root == NULL) return;

    inorderPrint(root->left);
    cout<<root->data<<" ";
    inorderPrint(root->right);
}

Node* builtTree(ll preorder[],ll inorder[],ll start,ll end){
    static ll idx = 0;

    if(start>end){
        return NULL;
    }

    ll curr = preorder[idx];
    idx++;
    Node* node = new Node(curr);

    if(start == end) return node;

    ll pos = position(inorder,curr,start,end);
    node->left = builtTree(preorder,inorder,start,pos-1);
    node->right = builtTree(preorder,inorder,pos+1,end);

    return node;
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll preorder[] = {1,2,4,3,5};
    ll inorder[] = {4,2,1,5,3};
    Node* root = builtTree(preorder,inorder,0,4);
    inorderPrint(root);
    return 0;
}