#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int romanToDecimal(string &s) {
        std::unordered_map<char,int> ump;
        ump['I'] = 1;
        ump['V'] = 5;
        ump['X'] = 10;
        ump['L'] = 50;
        ump['C'] = 100;
        ump['D'] = 500;
        ump['M'] = 1000;
        int count = 0;
        int i = 0;
        while(i<s.length()){
            if(ump[s[i]]<ump[s[i+1]]){
                count += ump[s[i+1]] - ump[s[i]];
                i = i + 2;
            }else{
                count += ump[s[i]];
                i++;
            }
        }
        return count;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.romanToDecimal(s) << endl;
    }
} 