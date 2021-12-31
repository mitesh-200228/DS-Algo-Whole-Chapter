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

void ConvertToDll(Node *root, Node *&prev, Node *&new_head, ll &k)
{
    if (!root)
        return;
    ConvertToDll(root->left, prev, new_head, k);
    if (k)
    {
        new_head = root;
        prev = root;
        k--;
    }
    else
    {
        prev->right = root;
        prev->right->left = prev;
        prev = prev->right;
    }
    ConvertToDll(root->right, prev, new_head, k);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    Node *new_head = NULL;
    Node *prev = NULL;
    ll k = 1;
    ConvertToDll(root, prev, new_head, k);

    Node *temp = new_head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->right;
    }

    return 0;
}