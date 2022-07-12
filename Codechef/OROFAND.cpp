#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ll long long
#define vec vector
#define vi vec<int>
#define vll vec<ll>
#define u_map unordered_map
#define u_set unordered_set
#define maxv(a) *max_element(a.begin(), a.end())
#define minv(a) *min_element(a.begin(), a.end())
#define pb push_back
#define ff first
#define ss second
#define yy cout << "Yes" << endl
#define nn cout << "No" << endl
#define YY cout << "YES" << endl
#define NN cout << "NO" << endl
#define c(x) cout << x << endl
#define f(i, a, b) for (int i = a; i < b; i++)
#define rf(i, a, b) for (int i = a - 1; i >= b; i--)
#define fast_io                       \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL)
#define all(x)  		x.begin(), x.end()
#define google(i,x)     cout<<"Case #"<<i<<": "<<x<<endl
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

const ll M = 1e9 + 7;

// ll gcd(ll a, ll b) { while (b) {a %= b; swap(a,b);} return a; }
// ll lcm(ll a, ll b) { ll g=gcd(a,b); ll res=a*(b/g); return res; }
// ll extended_gcd(ll a, ll b, ll &x, ll &y) { if (b==0) { x=1; y=0; return a; } ll x1,y1; ll g=extended_gcd(b,a%b,x1,y1); x=y1; y=x1-y1*(a/b); return g; }
// ll binExp(ll a, ll b, ll m=M) { a = a % m; ll res = 1; while (b) { if (b&1) { res=(res * a) % m; } a=(a * a) % m; b>>=1; } return res; }
// ll mod_inv(ll a, ll m=M) { a = a % m; return binExp(a,m-2,m); }		// only for prime m
// ll mod_add(ll a, ll b, ll m=M) { a = a % m; b = b % m; return (((a + b) % m) + m) % m; }
// ll mod_sub(ll a, ll b, ll m=M) { a = a % m; b = b % m; return (((a - b) % m) + m) % m; }
// ll mod_mul(ll a, ll b, ll m=M) { a = a % m; b = b % m; return (((a * b) % m) + m) % m; }
// ll mod_div(ll a, ll b, ll m=M) { a = a % m; ll binv = mod_inv(b,m); return (((a * binv) % m) + m) % m; }

// ll getBit(ll n, ll pos)
// {
//     return ((n & (1ll << pos)) != 0ll);
// }


// ll power(ll a,ll n)
// {
//     a%=M;
//     ll ans=1;
//     while(n>0)
//     {
//         if(n&1)
//             ans=(ans*a)%M;
//         a=(a*a)%M;
//         n=n>>1;
//     }
//     return ans;
// }

// int msbp(int num){
// 	if(num == 0)
// 		return 0;
// 	int block=1;
// 	while(num >> block) block++;
// 	return block;
// }
// __builtin_popcount (count no. of set bits)
// find_by_order(), order_of_key()

// int reverse(int n)
// {
// 	int r = 0;
// 	while(n > 0)
// 	{
// 		r = r*10 + n%10;
// 		n/= 10;
// 	}
// 	return r;
// }

void leftRotate(vector<int> &v, int n, int k)
{
	k%= n;
	reverse(v.begin(), v.begin()+k);
	reverse(v.begin()+k, v.begin()+n);
	reverse(v.begin(), v.begin()+n);
}

// void rightRotate(vector<int> &v, int n, int k)
// {
// 	k%= n;
// 	reverse(v.begin(), v.begin()+n);
// 	reverse(v.begin(), v.begin()+k);
// 	reverse(v.begin()+k, v.begin()+n);
// }


// *********	C O D E   **********



void solve()
{
	int n,q;
	cin>>n>>q;
	vi v(n), b(31,0);
	f(i,0,n)
	{
		cin>>v[i];
		f(j,0,31)
		{
			if(v[i] & (1<<j)) b[j]++;
		}
	}
	int k =0;
	f(i,0,31)
	{
		if(b[i] > 0) k+= (1<<i);
	}
	c(k);
	while(q--)
	{
		int ind, val; cin>>ind>>val;
		int ans=0;
		ind--;
		f(i,0,31)
		{
			if(v[ind]&(1<<i)) b[i]--;
			if(val & (1<<i)) b[i]++;
			if(b[i] > 0) ans+= (1<<i);
		}
		v[ind] = val;
		c(ans);
	}
}


int main()
{
	fast_io;
	int t = 1;
	cin >> t;
	while(t--)
	{
		solve();
	}

	return 0;
}
