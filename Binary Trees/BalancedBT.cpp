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

ll height(Node* root){
    if(root == NULL){
        return 0;
    }
    ll lh = height(root->left);
    ll rh = height(root->right);
    return max(lh,rh) + 1;
}

bool isBalanced(Node* root,ll* height){
    if(root == NULL) return true;
    ll lh = 0, rh = 0;
    if(isBalanced(root->left,&lh) == false){
        return false;
    }
    if(isBalanced(root->right,&rh) == false){
        return false;
    }
    *height = max(lh,rh) + 1;
    if(abs(lh-rh)<=1){
        return true;
    }else{
        return false;
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
    ll height = 0;
    // if(isBalanced(head,height))
    cout<<isBalanced(head,&height);
    return 0;
}