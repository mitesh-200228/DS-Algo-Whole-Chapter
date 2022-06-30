for (int i = 0; i < m; i++)
{
    a.push_back(b[i]);
    int x = a.size() - 1;
    while (x > 0)
    {
        if (a[(x - 1) / 2] < a[x])
        {
            int temp = a[x];
            a[x] = a[(x - 1) / 2];
            a[(x - 1) / 2] = temp;
            x = (x - 1) / 2;
        }
        else
            break;
    }
}
return a;