// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    bool isSafe(vector<vector<int>> &mat, int i, int j, int n, int m){
        if (i >= 0 && i < n && j >= 0 && j < m && mat[i][j] == 1)
            return true;
        return false;
    }
    void solve(vector<vector<int>> &mat, int i, int j, string path, vector<string> &res, vector<vector<bool>> &seen){
        int n = mat.size();
        int m = mat[0].size();
        if (i >= n - 1 && j >= m - 1){
            res.push_back(path);
            return;
        }
        seen[i][j] = true;
        if (isSafe(mat, i - 1, j, n, m) && seen[i - 1][j] == false)
        {
            path += "U";
            solve(mat, i - 1, j, path, res, seen);
            path.pop_back();
        }
        if (isSafe(mat, i + 1, j, n, m) && seen[i + 1][j] == false){
            path += "D";
            solve(mat, i + 1, j, path, res, seen);
            path.pop_back();
        }

        if (isSafe(mat, i, j - 1, n, m) && seen[i][j - 1] == false)
        {
            path += "L";
            solve(mat, i, j - 1, path, res, seen);
            path.pop_back();
        }

        if (isSafe(mat, i, j + 1, n, m) && seen[i][j + 1] == false)
        {
            path += "R";
            solve(mat, i, j + 1, path, res, seen);
            path.pop_back();
        }
        seen[i][j] = false;
    }

    vector<string> findPath(vector<vector<int>> &mat, int n){
        vector<string> res;
        vector<vector<bool>> seen(n, vector<bool>(n, false));
        if (mat[0][0] == 0)
            return res;
        if (mat[n - 1][n - 1] == 0)
            return res;
        solve(mat, 0, 0, "", res, seen);
        return res;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++)
                cout << result[i] << " ";
        cout << endl;
    }
    return 0;
} 