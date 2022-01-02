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
ll c = 0;
bool getDatas(ll x, Node *root2)
{
    if (!root2)
        return false;
    if (x == root2->data)
        return true;
    bool X=false,Y=false;
    if(x<root2->data) X = getDatas(x,root2->left); 
    else if(x>root2->data) Y = getDatas(x,root2->right);
    return X || Y;
}
void Sum(Node *root1, Node *root2, ll k)
{
    if (!root1)
        return;
    Sum(root1->left, root2, k);
    if (getDatas(k - root1->data, root2))
        c++;
    Sum(root1->right, root2, k);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // formation of BST 1
    Node *root1 = new Node(5);      /*             5        */
    root1->left = new Node(3);       /*           /   \      */
    root1->right = new Node(7);      /*         3     7     */
    root1->left->left = new Node(2);  /*    / \   / \    */
    root1->left->right = new Node(4); /*  2   4 6   8 */
    root1->right->left = new Node(6);
    root1->right->right = new Node(8);
    
    Node* root2 = new Node(10);           /*           10         */
    root2->left = new Node(6);       /*           /   \ */
    root2->right = new Node(15);     /*        6     15 */
    root2->left->left = new Node(3);  /*    / \   /  \ */
    root2->left->right = new Node(8); /*  3  8  11  18    */
    root2->right->left = new Node(11);
    root2->right->right = new Node(18);
    ll k;
    cin >> k;
    Sum(root1, root2, k);
    cout << c << endl;
    return 0;
}