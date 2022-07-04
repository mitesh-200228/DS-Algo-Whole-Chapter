#include <bits/stdc++.h>
using namespace std;
#define int int64_t

void solve() {
	int N, M, K;
	cin >> N >> M >> K;
	map<int, map<int, int>> A;
	int ans = 0;
	int dx[] = {1, 0, -1, 0};
	int dy[] = {0, 1, 0, -1};
	while(K--) {
		int x, y;
		cin >> x >> y;
		for(int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			ans += A[nx][ny] ? -1 : 1;
		}
		A[x][y] = 1;
	}
	cout << ans << endl;
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		solve();
	}
}
