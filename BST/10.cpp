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

void KthLargestElement(Node* root,ll k,int &x){
    if(!root || x>=k) return;
    KthLargestElement(root->right,k,x);
    x++;
    if(x == k){
        cout<<root->data<<" ";
        return;
    }  
    KthLargestElement(root->left,k,x);  
}

void KthSmallestElement(Node* root,ll k,int &y){
    if(!root || y>=k) return;
    KthSmallestElement(root->left,k,y);
    y++;
    if(y == k){
        cout<<root->data<<" ";
        return;
    }
    KthSmallestElement(root->right,k,y);
}

ll height(Node* root){
    if(!root) return 0;
    return max(height(root->left),height(root->right)) + 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    Node *root1 = new Node(100);
    root1->left = new Node(50);
    root1->right = new Node(300);
    root1->left->left = new Node(20);
    root1->left->right = new Node(70);
    ll k = 2;
    int x = 0,y = 0;
    ll h = height(root1);
    // cout<<h;
    KthLargestElement(root1,k,x);cout<<"\n";
    KthSmallestElement(root1,k,y);
    return 0;
}