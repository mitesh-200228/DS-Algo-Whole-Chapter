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

void printSubTreeNode(Node* root,ll k){
    if(root == NULL || k<0)
        return;
    if(k == 0)
        cout<<root->data<<" ";return;
    printSubTreeNode(root->left,k-1);
    printSubTreeNode(root->right,k-1);
}
//case 2
ll printNodesK(Node* root,Node* target,ll k){
    if(root == NULL){
        return -1;
    }
    if(root == target){
        printSubTreeNode(root,k);
        return 0;
    }
    ll dl = printNodesK(root->left,target,k);
    if(dl != -1){
        if(dl + 1 == k){
            cout<<root->data<<" ";
        }else{
            printSubTreeNode(root->right,target,k-dl-2);
        }
        return 1+dl;
    }

    ll dr = printNodesK(root->right,target,k);
    if(dr != -1){
        if(dr + 1 == k){
            cout<<root->data<<" ";
        }else{
            printSubTreeNode(root->left,target,k-dr-2);
        }
        return 1+dr;
    }
    return -1;
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
    return 0;
}