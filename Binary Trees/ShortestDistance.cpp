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
    Node* left;
    Node* right;

    Node(ll val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

Node* LCA(Node* root,ll n1,ll n2){
    if(root == NULL){   
        return NULL;    
    }
    if(root->data == n1 || root->data == n2){
        return root;
    }
    Node* left = LCA(root->left,n1,n2);
    Node* right = LCA(root->right,n1,n2);
    if(left != NULL && right!=NULL){
        return root;
    }
    if(left == NULL && right == NULL){
        return NULL;
    }
    if(left != NULL){
        return LCA(root->left,n1,n2);
    }
    return LCA(root->right,n1,n2);
}

ll findDist(Node* root,ll k,ll dist){
    if(root == NULL){
        return -1;
    }
    if(root->data == k){
        return dist;
    }
    ll left = findDist(root->left,k,dist+1);
    if(left!=-1){
        return left;
    }
    return findDist(root->right,k,dist+1);
}

ll distBtwNodes(Node* root,ll n1,ll n2){
    Node* lca = LCA(root,n1,n2);
    ll d1 = findDist(lca,n1,0);
    ll d2 = findDist(lca,n2,0);

    return d1+d2;
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
    cout<<distBtwNodes(head,7,5)<<endl;
    return 0;
}
