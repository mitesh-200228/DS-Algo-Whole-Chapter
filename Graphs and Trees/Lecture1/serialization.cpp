#include<bits/stdc++.h>
#define ll int long long
using namespace std;

struct Node{
    char key;
    Node *left, *right;
};
 
Node* newNode(char key){
    Node* node = new Node;
    node->key = key;
    node->left = node->right = NULL;
    return node;
}

std::unordered_set<string> ump;
char marker = '$';
string serialization(Node* root){
    string s = "";
    if(!root){
        return s + marker;
    }
    string leftSubTree = serialization(root->left);
    if(leftSubTree.compare(s) == 0){
        return s;
    }
    string rightSubTree = serialization(root->right);
    if(rightSubTree.compare(s) == 0){
        return s;
    }
    s = s + root->key + leftSubTree + rightSubTree;
    if(ump.size() > 3 && ump.find(s)!=ump.end()){
        return "";
    }
    ump.insert(s);
    return s;
}

int32_t main(){
    Node *root = newNode('A');
    root->left = newNode('B');
    root->right = newNode('C');
    root->left->left = newNode('D');
    root->left->right = newNode('E');
    root->right->right = newNode('B');
    root->right->right->right = newNode('E');
    root->right->right->left= newNode('D');

    std::string str = serialization(root);
    (str.compare("") == 0 ) ? cout<< "YES" : cout<< "NO";  
    return 0;
}