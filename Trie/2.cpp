#include "bits/stdc++.h"
#define ll int long long
using namespace std;

class TrieNode
{
public:
    TrieNode *next[2];
    TrieNode(){
        next[0] = NULL;
        next[1] = NULL;
    }
};

TrieNode* buildtrie(std::vector<ll> &v){
    TrieNode* root = new TrieNode();
    ll n = v.size();
    for(ll i=0;i<n;i++){
        ll num = v[i];   
        TrieNode* cur = new TrieNode();
        for(ll i=31;i>=0;i--){
            ll bit = 1&(num>>i);
            if(cur->next[bit] == NULL){
                cur->next[bit] = new TrieNode();
            }
            cur = cur->next[bit];
        }
    }
}

int32_t main()
{
    vector<ll> a = {3,10,5,15,2};
    TrieNode* root = buildtrie(a);
    return 0;
}