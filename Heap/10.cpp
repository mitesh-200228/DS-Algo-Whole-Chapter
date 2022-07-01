#include <bits/stdc++.h>
#define ll int long long
using namespace std;

struct Node{
    int data;
    Node *next;
    Node(int x){
        data = x;
        next = NULL;
    }
};

void printList(Node *node){
    while (node != NULL){
        printf("%d ", node->data);
        node = node->next;
    }
    cout << endl;
}

class Solution{
public:

    void addToTheEnd(Node* &head,ll val){
        if(head==NULL){
            head = new Node(val);
            return;
        }
        if(head->next==NULL){
            head->next = new Node(val);
            return;
        }
        Node* temp = head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next = new Node(val);
    }

    Node *mergeKLists(Node *arr[], int K){
        std::map<ll,ll> mp;
        ll n = arr.size();
        for(ll i=0;i<n;i++){
            mp[arr[i].data]++;   
        }
        Node* newone = NULL;
        for(auto s:mp) {
            while(s.second){
                addToTheEnd(newone,s.first);
                --s.second;
            }
        }
        return newone;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        struct Node *arr[N];
        for (int j = 0; j < N; j++)
        {
            int n;
            cin >> n;

            int x;
            cin >> x;
            arr[j] = new Node(x);
            Node *curr = arr[j];
            n--;

            for (int i = 0; i < n; i++)
            {
                cin >> x;
                Node *temp = new Node(x);
                curr->next = temp;
                curr = temp;
            }
        }
        Solution obj;
        Node *res = obj.mergeKLists(arr, N);
        printList(res);
    }
    return 0;
}