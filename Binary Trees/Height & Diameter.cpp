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

ll calculationOfHeight(Node* &root){
    if(root == NULL) return 0;

    ll lMax = calculationOfHeight(root->left);
    ll rMax = calculationOfHeight(root->right);
    return max(lMax,rMax) + 1;
}

ll calculationofDiameter(Node* &root,ll* height){

    if(root == NULL){
        *height = 0;
        return 0;
    }
    ll lh = 0;
    ll rh = 0;
    ll lDiameter = calculationofDiameter(root->left,&lh);
    ll rDiameter = calculationofDiameter(root->right,&rh);

    ll currDiameter = lh + rh + 1;
    *height = max(lh,rh) + 1;
    return max(currDiameter,max(lDiameter,rDiameter));
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
    // cout<<calculationOfHeight(head)<<endl;
    cout<<calculationofDiameter(head,0);
    return 0;
}