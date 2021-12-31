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
void insertAtTail(Node* &head,ll x){
    if(head == NULL){
        head = new Node(x);
        return;
    }
    Node* n = new Node(x);
    Node* temp = head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next = n;
}
void display(Node* &head){
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        if(temp->next==NULL){
            cout<<"NULL"<<endl;
        }
        temp=temp->next;
    }
    cout<<endl;
}
void checkPalindrom(Node* &head){
    Node* temp = head;
    Node* fast = head;
    Node* slow = head;

    while(fast->next->next!=NULL || fast->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;
        cout<<fast->data<<" "<<slow->data<<endl;
    }
    
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    Node* head = NULL;
    // Node* head2 = NULL;
    ll n = 5;
    for(ll i=1; i<=n ;i++){
        insertAtTail(head,i);   
    }
    display(head);
    checkPalindrom(head);
    return 0;
}