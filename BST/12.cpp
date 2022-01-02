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

void median(Node* root,float &count,float &sum){
    if(!root) return;
    median(root->left,count,sum);
    sum = sum + root->data;
    count++;
    median(root->right,count,sum);
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
    float count = 0;
    float sum = 0;
    median(root,count,sum);
    cout<<sum<<" "<<count<<endl;
    cout<<(sum/count)<<endl;
    return 0;
}