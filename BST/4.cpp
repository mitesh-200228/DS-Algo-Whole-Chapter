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

ll solve(Node* root,ll mn,ll mx){
    if(!root) return 1;
    if (root->data < mn || root->data > mx)
        return 0;
    return solve(root->left, mn, root->data-1) && solve(root->right, root->data+1, mx);
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
    ll min = INT_MIN;
    ll max = INT_MAX;
    cout<<solve(root,min,max);
    return 0;
}