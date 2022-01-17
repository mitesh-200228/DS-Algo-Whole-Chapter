// #include<unordered_set>
// #include<stack>
// #include<iostream>
// #include<vector>
// #include<string>
// #include<numeric>
// #include<algorithm>
// #include<queue>
// #include <stdio.h>
// #include<stack>
// #include<map>
// #include<unordered_map>
// #include<set>
// #include<climits>
// #include<cmath>
// #include<math.h>
// #include<limits>
// #define ll long long int
// const ll N = 1e5+ 2,MOD = 1e9+7;
// using namespace std;
// int power(ll a,ll b) {
//     ll ans = 1;
//     while(b>0){
//         if(b%2){
//             ans=ans*a;
//         }
//         a=a*a;b>>=1;
//     }
//     return ans;
// }
// ll countSetBits(ll n) {
//     ll count = 0;
//     while (n)
//     {
//         count += n & 1;
//         n >>= 1;
//     }
//     return count;
// }
 
// ll gcd(ll a, string b){
//     ll res = 0;
//     for (int i = 0; i < b.length(); i++){
//         res = ((res * 10) + (b[i] - '0')) % a;
//     }
//     return __gcd(a,res);
// }
 
// void solve(){
//     string s;cin>>s;
//     ll zero = 0,one = 0;
//     ll cnt = 0;
//     for(ll i=0;i<s.length();i++){
//         if(s[i] == '0') zero++;
//         else one++;
//         if(one == zero) cnt++;
//     }
//     if(one != zero) cout<<"-1"<<endl;
//     else cout<<cnt<<endl;
// }
 
// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);
 
//     ll t;
//     cin>>t;
//     while(t--)
//     {
//         solve();
//     }
//     return 0;
// }
// C++ implementation of the approach
#include <bits/stdc++.h>
using namespace std;

// Function to return the count
// of maximum substrings str
// can be divided into
int maxSubStr(string str, int n)
{

	// To store the count of 0s and 1s
	int count0 = 0, count1 = 0;

	// To store the count of maximum
	// substrings str can be divided into
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if (str[i] == '0') {
			count0++;
		}
		else {
			count1++;
		}
		if (count0 == count1) {
			cnt++;
		}
	}

	// It is not possible to
	// split the string
	if (count0!=count1) {
		return -1;
	}

	return cnt;
}

// Driver code
int main()
{
	string str = "10100100011011";
	int n = str.length();

	cout << maxSubStr(str, n);

	return 0;
}
