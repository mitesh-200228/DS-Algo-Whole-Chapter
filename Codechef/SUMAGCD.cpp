#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) // The function runs recursive in nature
{
    if (b == 0) // if b becomes 0 return a
        return a;
    return gcd(b, a % b); // divide to a by b to make smaller number
}

int t, n, a[100001];
int main()
{
    cin >> t;
    while (t--)
    {
        cin >> n;
        int max1 = 0, max2 = 0;
        for (int i = 0; i < n; i++)
        {
            scanf("%d", a + i);
            if (a[i] > max1)
                max1 = a[i];
        }
        for (int i = 0; i < n; i++)
        {
            if (a[i] > max2 && a[i] != max1)
                max2 = a[i];
        }
        if (max2 == 0)
        {
            max2 = max1;
            printf("%d\n", 2 * max1);
            continue;
        }

        int res1 = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i] != max1)
                res1 = gcd(res1, a[i]);
        }
        res1 += max1;

        int res2 = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i] != max2)
                res2 = gcd(res2, a[i]);
        }
        res2 += max2;
        if (res2 > res1)
            res1 = res2;
        printf("%d\n", res1);
    }
    return 0;
}