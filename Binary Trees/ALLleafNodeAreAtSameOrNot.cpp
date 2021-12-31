#include <unordered_set>
#include <stack>
#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <unordered_map>
#include <set>
#include <climits>
#include <cmath>
#include <math.h>
#include <limits>
#define ll long long int
const ll N = 1e5 + 2, MOD = 1e9 + 7;
using namespace std;

class Node
{
public:
    ll data;
    Node *left;
    Node *right;
    Node(ll val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};
int x = 1;
void solve(Node* root,ll h,ll &ans){
    if(!root) return;
    if(x == 0) return;
    if(!root->left && !root->right){
        if(ans == -1){
            h = 
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    Node *head = new Node(1);
    head->left = new Node(2);
    head->right = new Node(3);
    head->left->left = new Node(4);
    head->left->right = new Node(5);
    head->right->left = new Node(6);
    head->right->right = new Node(7);
    ll h = 0;
    solve(head,h,-1);
    return 0;
}