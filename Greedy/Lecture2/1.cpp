// https://www.codechef.com/problems/HW2C

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;

int main() {
    ll n;
    cin >> n;
    vector<pair<ll, ll>>exams(n);
    for(ll i = 0; i < n; i++) {
        cin >> exams[i].first >> exams[i].second;
    }
    sort(exams.begin(), exams.end());
    ll next_best = exams[0].second;
    for(ll i=0;i<n;i++)
    {
        if(exams[i].second >= next_best)
            next_best=exams[i].second;
        else 
            next_best=exams[i].first;
    }
    cout<<next_best<<endl;
}