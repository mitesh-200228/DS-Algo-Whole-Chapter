int kadane(vector<int> arr)
{
    int ans = INT_MIN, temp = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        temp += arr[i];
        ans = max(ans, temp);
        temp = max(temp, 0);
    }
    return ans;
}
int maximumSumRectangle(int R, int C, vector<vector<int>> M)
{
    int ans = INT_MIN;
    for (int i = 0; i < C; i++)
    {
        vector<int> t(R, 0);
        for (int j = i; j < C; j++)
        {
            for (int k = 0; k < R; k++)
                t[k] += M[k][j];
            ans = max(ans, kadane(t));
        }
    }
    return ans;
}