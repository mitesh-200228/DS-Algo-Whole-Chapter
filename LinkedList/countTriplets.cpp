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
std::unordered_map<ll,Node*> ump;
void triplets(Node* &head,ll x){
    Node* ptr1 = head;
    Node* ptr2 = head;
    for(Node* i=head;i->next!=NULL;i=i->next){
        ump[i->data] = i;
    }
    for(Node* j = head;j->next!=NULL;j=j->next){
        for(Node* k = j->next;k->next!=NULL;k=k->next){
            if(ump.find(x-(j->data+k->data))!=ump.end() && ump[x - (j->data + k->data)] && ump[x - (j->data + k->data)]!=k){
                cout<<j->data<<" "<<k->data<<" "<<(x-(j->data+k->data))<<endl;
            }
        }
    }
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
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    Node* head = NULL;
    // Node* head2 = NULL;
    ll n = 7;
    for(ll i=1; i<=n ;i++){
        insertAtTail(head,i);   
    }
    display(head);
    triplets(head,6);

    return 0;
}