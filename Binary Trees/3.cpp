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

ll findIn(ll Inorder[],ll start,ll end,ll curr){
    for(ll i=start; i<=end ;i++){
        if(Inorder[i] == curr){
            return i;
        }
    }   
    return -1;
}

Node* builtTree(ll postElement[],ll Inorder[],ll start,ll end){
    static ll idx = 4;
    if(start>end){
        return NULL;
    }

    ll curr = postElement[idx];
    idx--;
    Node* node = new Node(curr);
    if(start == end){
        return node;
    }
    
    ll curr1 = findIn(Inorder,start,end,curr);

    node->left = builtTree(postElement,Inorder,start,curr1-1);
    node->right = builtTree(postElement,Inorder,curr1+1,end);

    return node;
}

void inoderR(Node* &root){
    if(root == NULL){
        return;
    }
    inoderR(root->left);
    cout<<root->data<<" ";
    inoderR(root->right);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll postElement[] = {4,2,5,3,1};
    ll Inorder[] = {4,2,1,5,3};
    
    Node* node = builtTree(postElement,Inorder,0,4);
    inoderR(node);
    return 0;
}