#include <bits/stdc++.h>
using namespace std;
#define R 3
#define C 10

struct Pair {
	bool found;
	int value;
};
Pair findLongestPathUtil(int mat[R][C], int i, int j, int x,int y, bool visited[R][C]){
	if (i == x && j == y) {
		Pair p = { true, 0 };
		return p;
	}

	if (i < 0 || i >= R || j < 0 || j >= C || mat[i][j] == 0
		|| visited[i][j]) {
		Pair p = { false, INT_MAX };
		return p;
	}

	visited[i][j] = true;
	int res = INT_MIN;

	Pair sol = findLongestPathUtil(mat, i, j - 1, x, y, visited);
	if (sol.found)
		res = max(res, sol.value);
	sol = findLongestPathUtil(mat, i, j + 1, x, y, visited);
	if (sol.found)
		res = max(res, sol.value);

	sol = findLongestPathUtil(mat, i - 1, j, x, y, visited);

	if (sol.found)
		res = max(res, sol.value);

	sol = findLongestPathUtil(mat, i + 1, j, x, y, visited);

	if (sol.found)
		res = max(res, sol.value);

	visited[i][j] = false;

	if (res != INT_MIN) {
		Pair p = { true, 1 + res };
		return p;
	}

	else {
		Pair p = { false, INT_MAX };
		return p;
	}
}

void findLongestPath(int mat[R][C], int i, int j, int x,int y)
{
	bool visited[R][C];
	memset(visited, false, sizeof visited);
	Pair p = findLongestPathUtil(mat, i, j, x, y, visited);
	if (p.found)
		cout << "Length of longest possible route is "
			<< p.value;
	else
		cout << "Destination not reachable from given "
				"source";
}

int main()
{
	int mat[R][C] = { { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
					{ 1, 1, 0, 1, 1, 0, 1, 1, 0, 1 },
					{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 } };
	findLongestPath(mat, 0, 0, 1, 7);

	return 0;
}
