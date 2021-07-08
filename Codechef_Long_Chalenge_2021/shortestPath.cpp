#include <bits/stdc++.h>
using namespace std;
#define maxn 3E5 + 5
void solve()
{
    int n, m;
    cin >> n >> m;
    int a[n];
    int b[m];
    int i, j;
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (i = 0; i < m; i++)
    {
        cin >> b[i];
    }
    int max_i = maxn;
    int rough[n];
    int low = -1, high = -1;
    for (i = 0; i < n; i++)
    {
        if (i == 0)
        {
            rough[i] = 0;
        }
        else if (a[i] != 0)
        {
            rough[i] = 0;
        }
        else
        {
            rough[i] = max_i;
        }
    }
    for (i = 0; i < n; i++)
    {
        if (a[i] == 1)
        {
            high = i;
        }
        if (high != -1)
        {
            if (a[i] == 0)
            {
                rough[i] = min(rough[i], i - high);
            }
        }
    }
    for (i = n - 1; i >= 0; i--)
    {
        if (a[i] == 2)
        {
            low = i;
        }
        if (low != -1)
        {
            if (a[i] == 0)
            {
                rough[i] = min(rough[i], low - i);
            }
        }
    }
    for (i = 0; i < m; i++)
    {
        j = b[i] - 1;
        if (rough[j] != max_i)
        {
            cout << rough[j] << " ";
        }
        else
        {
            cout << -1 << " ";
        }
    }
    cout << endl;
}
int main()
{
    int test;
    cin >> test;
    while (test--)
    {
        solve();
    }
}