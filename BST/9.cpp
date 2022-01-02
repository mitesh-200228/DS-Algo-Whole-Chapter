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
std::vector<ll> v1;
std::vector<ll> v2;
std::vector<ll> v3;

void BSTtoArray1(Node* root){
    if(!root) return;
    BSTtoArray1(root->left);
    v1.push_back(root->data);
    BSTtoArray1(root->right);
}

void BSTtoArray2(Node* root){
    if(!root) return;
    BSTtoArray2(root->left);
    v2.push_back(root->data);
    BSTtoArray2(root->right);
}

void mergeArrays(){
    ll i = 0;
    ll j = 0;
    while(i<v1.size() && j<v2.size()){
        if(v1[i] < v2[j]){
            v3.push_back(v1[i]);
            i++;
        }else if(v1[i] > v2[j]){
            v3.push_back(v2[j]);
            j++;
        }else{
            v3.push_back(v1[i]);
            i++;j++;
        }
    }
    if(i<v1.size()){
        while(i<v1.size()){
            v3.push_back(v1[i]);i++;
        }
    }
    else if(j<v2.size()){
        while(j<v2.size()){
            v3.push_back(v2[j]);j++;
        }
    }

    for(auto i:v3){
        cout<<i<<" ";
    }cout<<endl;
}

Node* mergeBST(ll start,ll end){
    ll mid = start + (end-start)/2;
    if(start > end){
        return NULL;
    }
    Node* root = new Node(v3[mid]);
    root->left = mergeBST(start,mid-1);
    root->right = mergeBST(mid+1,end);
    return root;
}

void inorder(Node* root){
    if(!root) return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void preorder(Node* root){
    if(!root) return;
    cout<<root->data<<" ";
    inorder(root->left);
    inorder(root->right);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    Node *root1 = new Node(100);
    root1->left     = new Node(50);
    root1->right = new Node(300);
    root1->left->left = new Node(20);
    root1->left->right = new Node(70);

    Node *root2 = new Node(80);
    root2->left = new Node(40);
    root2->right = new Node(120);
    BSTtoArray1(root1);
    BSTtoArray2(root2);
    mergeArrays();
    Node* Answer = mergeBST(0,v3.size()-1);
    inorder(Answer);
    preorder(Answer);
    return 0;
}