#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0); cin.tie(0)
#define file freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout)
#define ff first
#define ss second
#define pb push_back
#define pf push_front
#define all(s) s.begin(),s.end()
typedef long long ll;
typedef pair<ll,ll> pi;
typedef pair<pi,ll> pii;
void solve()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,m;
        cin>>n>>m;
        ll a[n+10],b[n+10],c[n+10];
        ll i,j=0,k=0;
        for(i=1;i<=n;i++)
        {

            cin>>a[i];
        }
        ll s=0;
        for(i=1;i<=n;i++)
        {
            if(a[i]==1)s=i;
            b[i]=s;
        }
        s=0;
        for(i=n;i>0;i--)
        {
            if(a[i]==2)s=i;
            c[i]=s;
        }
        for(i=0;i<m;i++)
        {
            ll y,ans;
            cin>>y;
            if(y==1)ans=0;
            else if(b[y]==0&&c[y]==0)ans=-1;
            else if(b[y]==0)ans=abs(y-c[y]);
            else if(c[y]==0)ans=abs(b[y]-y);
            else ans=min(abs(b[y]-y),abs(c[y]-y));
            cout<<ans<<" ";

        }
        cout<<"\n";
    }
}
int main()
{
    fast;
    solve();
}
