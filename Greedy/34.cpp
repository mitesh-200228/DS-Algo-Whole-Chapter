if (S > (D * 9))
{
    return "-1";
}
string ans;
while (D > 0)
{
    if (S >= 10)
    {
        ans.push_back('9');
        S -= 9;
    }
    else if (S < 10 && D > 1)
    {
        ans.push_back((S - 1) + 48);
        S = 1;
    }
    else if (D > 1 && S == 1)
    {
        ans.push_back('0');
    }
    else
    {
        ans.push_back((S) + 48);
    }
    D--;
}
int n = ans.length();
for (int i = 0, j = n - 1; i < n / 2; i++, j--)
{
    swap(ans[i], ans[j]);
}
return ans;