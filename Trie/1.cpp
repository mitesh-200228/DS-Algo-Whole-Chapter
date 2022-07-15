#include "bits/stdc++.h"
using namespace std;
#define ll int long long

class Trie
{
public:
    class Node
    {
    public:
        bool end;
        Node *next[26];
        Node()
        {
            end = false;
            for (ll i = 0; i < 26; i++)
            {
                next[i] = NULL;
            }
        }
    };
    Node* trie;
    Trie(){
        trie = new Node();
    }
    void insert(string word){
        ll i = 0;
        Node* it = trie;
        while (i<word.size()){
            if(it->next[word[i] - 'a'] == NULL){
                it->next[word[i] - 'a'] = new Node();
            }
            it = it->next[word[i] - 'a'];
            i++;
        }
        it->end = true;
    }
    bool search(string word){
        ll i = 0;
        Node* it = trie;
        while (i<word.size())
        {
            if(it->next[word[i] - 'a'] == NULL){
                return false;
            }
            it = it->next[word[i]-'a'];
            i++;
        }
        return it->end;
    }
};

int32_t main()
{
    Trie *myTrie = new Trie();
    std::vector<string> words = {"mitesh","bediya"};
    for(auto w:words){
        myTrie->insert(w);
    }
    if(myTrie->search("mitesh")){
        cout<< "Mitesh found\n";
    }else{
        cout<<"Mitesh doesn't exists";
    }
    return 0;
}