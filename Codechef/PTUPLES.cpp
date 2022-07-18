#include <iostream>
#include <bits/stdc++.h>
using namespace std;
bool isprime(int n)
{
    if (n == 1)
        return false;
    else if (n == 2 || n == 3)
        return true;
    else
    {
        for (int i = 2; i <= sqrt(n); i++)
        {
            if (n % i == 0)
                return false;
        }
        return true;
    }
}

int main()
{
    const int N = 1000001;
    vector<bool> prime(N, false);
    for (int i = 2; i < N; i++)
        prime[i] = isprime(i);
    vector<int> ans(N, 0);
    int cnt = 0;
    for (int i = 5; i < N; i++)
    {
        if (prime[i] && prime[i - 2])
            cnt++;

        ans[i] = cnt;
    }
    int t;
    int n;
    cin >> t;
    while (t > 0)
    {
        cin >> n;
        cout << ans[n] << endl;
        t--;
    }
    // your code goes here
    return 0;
}
