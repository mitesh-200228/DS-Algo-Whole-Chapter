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

void count(Node* &root){
    if(root == NULL){
        return;
    }
    std::queue<Node*> q;
    q.push(root);
    q.push(NULL);
    ll count = 0;
    ll sum = 0;
    while (!q.empty()){
        Node* node = q.front();
        q.pop();
        if(node!=NULL){
            count++;
            sum += node->data;
            if(node->left){
                q.push(node->left);
            }
            if(node->right){
                q.push(node->right);
            }
        }else if(!q.empty()){
            q.push(NULL);
        }
    }
    cout<<"Count: "<<count<<endl;
    cout<<"Sum: "<<sum<<endl;
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
    count(head);
    return 0;
}