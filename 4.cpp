#include <bits/stdc++.h>
using namespace std;

#define ll          long long



signed main(){

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif



    int tc = 0, tt = 1;
    cin >> tt;
    while (tc++ < tt)
    {

        ll n, k;
        cin >> n >> k;
        vector<ll> arr(1, 1);
        k -= n;

        ll curr = 2;

        for (int i = 2; i <= n; i++) {
            if (k < arr.size()) {
                int val = arr[arr.size()- k- 1];
                arr.push_back(val);
                break;
            }
            k -= arr.size();
            arr.push_back(curr);
            curr++;
        }

        while (arr.size() < n) {
            arr.push_back(arr.back());
        }

        for(auto x: arr){
            cout << x << " ";
        }cout << endl;




    }

    return 0;
}