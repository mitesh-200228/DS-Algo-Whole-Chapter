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
    Node* next;
    ll data;

    Node(ll val){
        data = val;
        next = NULL;
    }
};

class DoublyNode{
    public:
    DoublyNode* previous;
    DoublyNode* next;
    ll data;

    DoublyNode(ll val){
        data = val;
        previous = NULL;
        next = NULL;
    }
};

void print(Node* &head){
    Node* temp = head;
    if(temp == NULL){
        return;
    }
    else if(temp->next == NULL){
        cout<<temp->data<<endl;
        return;
    }else{
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp = temp->next;
            if(temp->next == NULL){
                cout<<"NULL"<<endl;
            }
        }
    }
}

void deletion(Node* &head,ll pos){
    Node* temp = head;
    ll x = 1;
    while(pos>x){
        temp = temp->next;
        x++;
    }
    Node* todelete = temp->next;
    temp->next = temp->next->next;
    delete todelete;
}

Node* reverse(Node* &head){
    Node* prevptr = NULL;
    Node* currptr = head;
    Node* nextptr;

    while(currptr!=NULL){
        nextptr = currptr->next;
        currptr->next = prevptr;
        prevptr = currptr;
        currptr = nextptr; 
    }
    return prevptr;
}

Node* reverserecurrsive(Node* &head){

    if(head == NULL || head->next==NULL){
        return head;
    }

    Node* newhead = reverserecurrsive(head->next);
    head->next->next = head;
    head->next = NULL;
    return newhead;
}

Node* reverseKNodes(Node* &head,ll k){
    Node* prevptr = NULL;
    Node* currptr = head;
    Node* nextptr;
    ll count = 0;
    while(currptr!=NULL && count<k){
        nextptr = currptr->next;
        currptr->next = prevptr;
        prevptr = currptr;
        currptr = nextptr;
        count++;
    }
    if(nextptr!=NULL){
        head->next = reverseKNodes(nextptr,k);
    }
    return prevptr;
}

void createCycle(Node* &head,ll pos){
    Node* temp = head;
    Node* startPoint;  
    ll count = 1;
    while(temp->next!=NULL){
        if(count==pos){
            startPoint = temp;
        }
        temp=temp->next;
        count++;
    }
    temp->next=startPoint;
}

void deleteCycle(Node* &head){
    Node* slow = head;
    Node* fast = head;
    do{
        slow = slow->next;
        fast = fast->next->next;
    }while(slow!=fast);
    fast = head;
    while(slow->next!=fast->next){
        slow=slow->next;
        fast=fast->next;
    }
    slow->next=NULL;
}

bool detectcycle(Node* &head){
    Node* slow = head;
    Node* fast = head;
    while (fast->next!=NULL && fast!=NULL){
        fast = fast->next->next;
        slow = slow->next;

        if(slow == fast){
            return true;
        }
    }
    return false;
}

void insertAtTail(Node* &head,ll x){
    Node* temp = head;
    Node* n = new Node(x);
    if(head == NULL){
        head = n;
        return;
    }
    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->next = n;
}

void display(Node* head){
    Node* temp = head;
    while(temp!=NULL){
        if(temp->next == NULL){
            cout<<temp->data<<"->NULL"<<endl;
        }
        else{
            cout<<temp->data<<"->";
        }
        temp = temp->next;
    }
}

void insertAtHead(DoublyNode* &head,ll x){
    DoublyNode* n = new DoublyNode(x);
    n->next = head;
    if(head!=NULL){
        head->previous = n;
    }
    head = n;
    n->previous = NULL; 
}

void displayDouble(DoublyNode* &head){
    DoublyNode* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        if(temp->next==NULL){
            cout<<"NULL"<<endl;
        }
        temp=temp->next;
    }
}

void insertAtTailDoubly(DoublyNode* &head,ll x){
    DoublyNode* n = new DoublyNode(x);
    DoublyNode* temp = head;

    if(head == NULL) {
        insertAtHead(head,x);
        return;
    }
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=n;
    n->previous=temp;
}

ll length(Node* &head){
    if(head == NULL){
        return 0;
    }
    ll count = 0;
    Node* temp = head;
    while(temp!=NULL){
        temp=temp->next;
        cout<<temp->data<<" ";
        count++;
    }
    cout<<endl;
    return count;
}

Node* AppendLastKNodes(Node* &head,ll k){
    Node* newHead;
    Node* newTail;
    Node* tail = head;

    ll l = length(head);ll x = l;
    ll count = 1;
    while(tail->next!=NULL){
        if(count == l-k){
            newTail = tail;
        }
        if(count-1 == l-k){
            newHead = tail;
        }
        tail = tail->next;
        count++;
    }
    newTail->next = NULL;
    tail->next = head;
    return newHead;
}

void internsect(Node* &Link1,Node* &Link2,ll pos){
    Node* temp1 = Link1;
    pos--;
    while(pos--){
        temp1=temp1->next;
    }
    Node* temp2 = Link2;
    while(temp2->next!=NULL){
        temp2=temp2->next;
    }
    temp2->next=temp1;
}

void findIntersectionPoint(Node* &Link1,Node* &Link2){

    ll length1 = length(Link1);
    ll length2 = length(Link2);

    if(length1 < length2){
        findIntersectionPoint(Link2,Link1);
        return;
    }
    Node* temp1 = Link1;
    Node* temp2 = Link2;
    ll d = length1-length2;
    while(d--){
        temp1=temp1->next;
    }
    while(temp1->next!=temp2->next){
        temp1=temp1->next;
        temp2=temp2->next;
    }
    cout<<temp1->next->data<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n = 10;
    Node* head = NULL;
    for(ll i=0; i<n ;i++){
        insertAtTail(head,i);
    }   
    display(head);
    deletion(head,3);
    Node* newhead = reverseKNodes(head,3); // Node* newhead = reverse(head);
    display(newhead); 
    createCycle(head,3);
    cout<<detectcycle(head)<<endl;
    deleteCycle(head);
    cout<<detectcycle(head)<<endl;
    DoublyNode* DoubleHead = NULL;
    for(ll i=0; i<n ;i++){
        insertAtTailDoubly(DoubleHead,i); 
    }
    displayDouble(DoubleHead);
    Node* headK = NULL;
    for(ll i=0; i+5<n ;i++){
        insertAtTail(headK,i);
    }
    display(headK);
    Node* KHeads = AppendLastKNodes(headK,2);
    display(KHeads);
    Node* Link1 = NULL;
    Node* Link2 = NULL;
    insertAtTail(Link1,1);
    insertAtTail(Link1,2);
    insertAtTail(Link1,3);
    insertAtTail(Link1,4);
    insertAtTail(Link1,5);
    insertAtTail(Link1,6);
    insertAtTail(Link2,8);
    insertAtTail(Link2,9);
    insertAtTail(Link2,5);
    insertAtTail(Link2,6);
    display(Link1);display(Link2);
    internsect(Link1,Link2,2);
    findIntersectionPoint(Link1,Link2);
    return 0;
}
