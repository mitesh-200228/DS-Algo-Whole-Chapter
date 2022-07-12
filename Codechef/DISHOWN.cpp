#include<bits/stdc++.h>
using namespace std;

#define ll long long
 
void run() {
#ifndef ONLINE_JUDGE
	freopen("input.txt" , "r" , stdin);
	freopen("output.txt" , "w"  , stdout);
#endif
}
int * parent;
int * score;
int find(int x){
	if(parent[x] == x) return parent[x];
	else{
		parent[x] = find(parent[x]);
		return parent[x];
	}
}
void Union(int xlead , int ylead){
	if(score[xlead] < score[ylead]){
		parent[xlead] = ylead;
	}else if(score[xlead] > score[ylead]){ 
		parent[ylead] = xlead;
	}
}
void solve() {
	int n;
	cin >> n; // No. Of Chefs;
	score = new int[n + 1];
	parent = new int[n + 1];
	for(int i = 1; i <= n ; i++) { 
		cin >> score[i];
		parent[i] = i;
	}
	int q;
	cin >> q;
	for(int i = 0 ; i < q ; i++){
		int type;
		cin >> type;
		if(type == 0){
			int x , y;
			cin >> x >> y;
			int xlead = find(x);
			int ylead = find(y);
			if(xlead != ylead){
				Union(xlead , ylead);
			}else{
				cout << "Invalid query!" << endl;
			}
		}else{
			int x;
			cin >> x;
			int xlead = find(x);
			cout << xlead  << endl;
		}
	}

}
int main() {
	run();
	ios_base::sync_with_stdio(0);
    	cin.tie(0); cout.tie(0);
    	int t;
    	cin >> t;
    	while(t--)
		solve();

}