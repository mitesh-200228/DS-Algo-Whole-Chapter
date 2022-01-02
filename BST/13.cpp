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
 
struct Node
{
    ll data;
    Node *left, *right, *next;
    Node(ll val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};
vector<pair<ll,ll>> p(1);
void countBSTFromGivenRange(Node* root,ll l,ll h){
    if(!root) return;  
    countBSTFromGivenRange(root->left,l,h); 
    if(root->data >= l && root->data <= h) p[0].first++;
    countBSTFromGivenRange(root->right,l,h);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    Node *root = new Node(5);      /*             5        */
    root->left = new Node(3);       /*          /   \      */
    root->right = new Node(7);      /*         3     7     */
    root->left->left = new Node(3);  /*       / \   / \    */
    root->left->right = new Node(4); /*      2   4 6   8 */
    root->right->left = new Node(6);
    root->right->right = new Node(8);
    ll l,h;cin>>l>>h;
    countBSTFromGivenRange(root,l,h);
    cout<<p[0].first<<endl;
    // countBSTFromGivenRange2(root,h);
    return 0;
}