#include<iostream>
#define ll int long long
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* bottom;

    Node(int val){
        data = val;
        next = NULL;
        bottom = NULL;
    }
};

void insertAtHead(Node* &head,ll x){
    Node* n = new Node(x);
    n->next = head;
    head = n; 
}

void insertAtTail(Node* &head,ll x){
    if(head == NULL){
        insertAtHead(head,x);
        return;
    }
    Node* temp = head;
    Node* n = new Node(x);
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next = n;
}

void insertAtBottom(Node* head,ll x){
    Node* Y = new Node(x);
    Node* temp = head;

    while(temp->bottom!=NULL){
        temp=temp->bottom;
    }    

    temp->bottom = Y;
}

void display(Node* head){
    Node* temp = head;
    while(temp->next!=NULL){
        Node* temp1 = temp;
        cout<<temp1->data<<"**";
        while(temp1->bottom!=NULL){
            cout<<temp1->bottom->data<<"--";
            temp1=temp1->bottom;
        }
        temp=temp->next;
    }
}

int main(){
    Node* head = NULL;
    for(ll i=0; i<6 ;i++){
        insertAtTail(head,i);
            insertAtBottom(head,i);
        for(ll i=2; i<4 ;i++){
        }
    }
    display(head);
    return 0;
}