#include <bits/stdc++.h>
using namespace std;

int getMinDiff(int arr[], int n, int k)
{
    sort(arr, arr + n);
    int ans = arr[n - 1] - arr[0]; 

    int tempmin, tempmax;
    tempmin = arr[0];
    tempmax = arr[n - 1];

    for (int i = 1; i < n; i++) {
        if(arr[i] - k < 0) 
        continue;
        tempmin= min(arr[0] + k,arr[i] - k); 
        tempmax = max(arr[i - 1] + k, arr[n - 1] - k); 
        ans = min(ans, tempmax - tempmin); 
    }
    return ans;
}

// Driver Code Starts
int main()
{
    int k = 6, n = 6;
    int arr[n] = { 7, 4, 8, 8, 8, 9 };
    int ans = getMinDiff(arr, n, k);
    cout << ans;
}