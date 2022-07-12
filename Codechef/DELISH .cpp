#include <bits/stdc++.h>
#define int long long int
#define fio                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
using namespace std;

void solve(int test_case)
{
    int N;
    cin >> N;
    vector<int> D(N);
    for (int i = 0; i < N; i++)
        cin >> D[i];
    vector<int> leftMax(N), leftMin(N), rightMax(N), rightMin(N);
    leftMax[0] = D[0];
    leftMin[0] = D[0];
    for (int i = 1; i < N; i++)
    {
        leftMax[i] = max(D[i], D[i] + leftMax[i - 1]);
        leftMin[i] = min(D[i], D[i] + leftMin[i - 1]);
    }
    rightMax[N - 1] = D[N - 1];
    rightMin[N - 1] = D[N - 1];
    for (int i = N - 2; i >= 0; i--)
    {
        rightMax[i] = max(D[i], D[i] + rightMax[i + 1]);
        rightMin[i] = min(D[i], D[i] + rightMin[i + 1]);
    }
    for (int i = 1; i < N; i++)
    {
        leftMax[i] = max(leftMax[i], leftMax[i - 1]);
        leftMin[i] = min(leftMin[i], leftMin[i - 1]);
    }
    int ans = INT_MIN;
    for (int i = 0; i < N - 1; i++)
    {
        ans = max(leftMax[i] - rightMin[i + 1], ans);
        ans = max(rightMax[i + 1] - leftMin[i], ans);
    }
    cout << ans << "\n";
}

int32_t main()
{
    fio int T;
    cin >> T;
    for (int t = 1; t <= T; t++)
        solve(t);
    return 0;
}