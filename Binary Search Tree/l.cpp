#include<bits/stdc++.h>
#define ll int long long
using namespace std;

struct Node{
    Node* next;
    ll data;
    Node(ll val){
        data = val;
        next = NULL;
    }
};

void append(Node* &head,ll k){
    if(!head){
        head = new Node(k);
        return;
    }
    if(head->next == NULL){
        head->next = new Node(k);
        return;
    }
    Node* temp = head;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->next = new Node(k);
    return;
}

void print(Node* head){
    Node* temp = head;
    while(temp){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

Node* sum(Node* head1,Node* head2){
    if(!head1){
        return head2;
    }
    if(!head2){
        return head1;
    }
    stack<ll> s1;
    stack<ll> s2;
    Node* temp = head1;
    while(temp != NULL){
        s1.push(temp->data);
        temp = temp->next;
    }
    Node* temp1 = head2;
    while(temp1 != NULL){
        s2.push(temp1->data);
        temp1 = temp1->next;
    }
    Node* answer = NULL;
    ll c = 0;
    while(!s1.empty() || !s2.empty()){
        ll tp1 = 0;
        ll tp2 = 0;
        if(!s1.empty()){
            tp1 = s1.top();
            s1.pop();
        }
        if(!s2.empty()){
            tp2 = s2.top();
            s2.pop();
        }
        ll ans = tp1 + tp2 + c;
        ll rem = ans%10;
        c = ans/10;
        Node* temp = new Node(rem);
        if(!answer){
            answer = temp;
        }else{
            temp->next = answer;
            answer = temp;
        }
    }
    return answer;
}

int32_t main(){
    Node* head1 = NULL;
    Node* head2 = NULL;
    for(ll i=1;i<6;i++){
        append(head1,i);
    }
    for(ll i=4;i>0;i--){
        append(head2,i);
    }
    // print(head1);
    // print(head2);
    Node* sym = sum(head1,head2);
    print(sym);
    return 0;
}