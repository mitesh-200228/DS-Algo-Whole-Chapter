int dp[52][52];

int area(int i, int j, vector<vector<int>> &mat)
{

    if (i < 0 || j < 0)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    int left = area(i, j - 1, mat);
    int top = area(i - 1, j, mat);
    int diag = area(i - 1, j - 1, mat);

    int side = 0;

    if (mat[i][j] != 0)
    {
        side = 1 + min({left, top, diag});
    }

    ans = max(ans, side);

    return dp[i][j] = side;
}