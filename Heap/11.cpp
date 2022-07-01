#include <bits/stdc++.h>
using namespace std;
#define N 1000

class Solution
{
public:
    pair<int, int> findSmallestRange(int arr[][N], int n, int k)
    {
        multiset<pair<int, pair<int, int>>> s;

        for (int i = 0; i < k; i++)
        {
            s.insert({arr[i][0], {i, 0}});
        }

        int maxi = INT_MAX, mini = 0;

        while (true)
        {
            auto node1 = *s.begin();
            auto node2 = *(--s.end());
            int low = node1.first;
            int high = node2.first;

            if (high - low < maxi - mini)
            {
                maxi = high;
                mini = low;
            }

            auto node = *s.begin();
            s.erase(s.begin());

            int ele = node.first, row = node.second.first, col = node.second.second;
            col = col + 1;
            if (col < n)
            {
                s.insert({arr[row][col], {row, col}});
            }
            else
            {
                break;
            }
        }

        return {mini, maxi};
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int arr[N][N];
        pair<int, int> rangee;
        for (int i = 0; i < k; i++)
            for (int j = 0; j < n; j++)
                cin >> arr[i][j];
        Solution obj;
        rangee = obj.findSmallestRange(arr, n, k);
        cout << rangee.first << " " << rangee.second << "\n";
    }
    return 0;
}