#include <iostream>
using namespace std;

struct Node{
    int key;
    struct Node *left, *right;
};

void findPreSuc(Node *root, Node *&pre, Node *&suc, int key)
{
    if (root == NULL)
        return;
    if (root->key == key){
        if (root->left != NULL){
            Node *tmp = root->left;
            while (tmp->right)
                tmp = tmp->right;
            pre = tmp;
        }

        if (root->right != NULL){
            Node *tmp = root->right;
            while (tmp->left)
                tmp = tmp->left;
            suc = tmp;
        }
        return;
    }
    if (root->key > key){
        suc = root;
        findPreSuc(root->left, pre, suc, key);
    }
    else{
        pre = root;
        findPreSuc(root->right, pre, suc, key);
    }
}

Node *newNode(int item){
    Node *temp = new Node;
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}
Node *insert(Node *node, int key){
    if (node == NULL)
        return newNode(key);
    if (key < node->key)
        node->left = insert(node->left, key);
    else
        node->right = insert(node->right, key);
    return node;
}

int main()
{
    int key = 65;
    Node *root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
    Node *pre = NULL, *suc = NULL;
    findPreSuc(root, pre, suc, key);
    if (pre != NULL)
        cout << "Predecessor is " << pre->key << endl;
    else
        cout << "No Predecessor";
    if (suc != NULL)
        cout << "Successor is " << suc->key;
    else
        cout << "No Successor";
    return 0;
}
