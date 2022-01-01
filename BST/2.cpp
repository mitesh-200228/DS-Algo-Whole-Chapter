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

ll min1(Node* root){
    if(root->left) return min1(root->left);
    else return root->data;
}

ll max1(Node* root){
    if(root->right) return max1(root->right);
    else return root->data;
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
    cout<<min1(root)<<endl;
    cout<<max1(root);
    return 0;
}