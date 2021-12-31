// A dynamic programming based
// solution for 0-1 Knapsack problem
#include <bits/stdc++.h>
using namespace std;

// A utility function that returns
// maximum of two integers
int max(int a, int b)
{
    return (a > b) ? a : b;
}

// Returns the maximum value that
// can be put in a knapsack of capacity W
int knapSack(int W, int wt[], int val[], int n)
{
    int i, w;
    vector<vector<int>> K(n + 1, vector<int>(W + 1));

    // Build table K[][] in bottom up manner
    for (i = 0; i <= n; i++)
    {
        for (w = 0; w <= W; w++)
        {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (wt[i - 1] <= w)
                K[i][w] = max(val[i - 1] + K[i - 1][w - wt[i - 1]],K[i - 1][w]);
            else
                K[i][w] = K[i - 1][w];
        }
    }
    return K[n][W];
}

// Driver Code
int main()
{
    int val[] = {60, 100, 120};
    int wt[] = {10, 20, 30};
    int W = 50;
    int n = sizeof(val) / sizeof(val[0]);

    cout << knapSack(W, wt, val, n);

    return 0;
}

// This code is contributed by Debojyoti Mandal



//-------------------------------------------------------1D DP
// #include <bits/stdc++.h>
// using namespace std;
// int knapSack(int W, int wt[], int val[], int n)
// {
// 	// making and initializing dp array
// 	int dp[W + 1];
// 	memset(dp, 0, sizeof(dp));

// 	for (int i = 1; i < n + 1; i++) {
// 		for (int w = W; w >= 0; w--) {

// 			if (wt[i - 1] <= w)
// 				// finding the maximum value
// 				dp[w] = max(dp[w],
// 							dp[w - wt[i - 1]] + val[i - 1]);
// 		}
// 	}
// 	return dp[W]; // returning the maximum value of knapsack
// }
// int main()
// {
// 	int val[] = { 60, 100, 120 };
// 	int wt[] = { 10, 20, 30 };
// 	int W = 50;
// 	int n = sizeof(val) / sizeof(val[0]);
// 	cout << knapSack(W, wt, val, n);
// 	return 0;
// }
