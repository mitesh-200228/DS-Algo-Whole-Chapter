#include <unordered_set>
#include <stack>
#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <unordered_map>
#include <set>
#include <climits>
#include <cmath>
#include <math.h>
#include <limits>

#define ll long long int
const ll N = 1e5 + 2, MOD = 1e9 + 7;
using namespace std;

class Node
{
public:
    Node *next;
    ll data;
    Node(ll val)
    {
        data = val;
        next = NULL;
    }
};

void insertAtHead(Node* &head,ll x){
    Node* n = new Node(x);
    if(head == NULL){
        n->next = n;
        head = n;
        return;
    }

    Node* temp = head;
    while(temp->next!=head){
        temp=temp->next;
    }
    temp->next = n;
    n->next = head;
    head=n;
}

void insertAtTail(Node *&head, ll x)
{
    if (head == NULL)
    {
        insertAtHead(head,x);
        return;
    }
    Node *n = new Node(x);
    Node *temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    temp->next = n;
    n->next = head;
}

void display(Node *&head){
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        if (temp->next == NULL)
        {
            cout <<"NULL"<< endl;
        }
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    Node *head = NULL;
    // Node* head2 = NULL;
    ll n = 3;
    for (ll i = 1; i <= n; i++)
    {
        insertAtTail(head, i);
    }
    display(head);
    return 0;
}