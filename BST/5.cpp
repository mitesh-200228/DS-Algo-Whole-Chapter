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

void populate(Node* root,Node* prev){
    if(!root) return;
    populate(root->left,prev);
    if(prev!=NULL){
        prev->next = root; 
    }
    prev = root;
    populate(root->right,prev);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    Node* root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(50);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right->right = new Node(6);
    Node* prev = NULL;
    populate(root,prev);
    return 0;
}