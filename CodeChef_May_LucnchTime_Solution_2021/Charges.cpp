// LunchTtime Sol.
#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{

    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    int len = n - 1;
    for (ll i = 1; i < n; i++)
    {
        if (s[i] == s[i - 1])
        {
            len += 1;
        }
    }

    while (k--)
    {
        /* code */
        ll q;
        cin >> q;
        q--;

        if (s[q] == '1')
        {
            s[q] = '0';
        }
        else
        {
            s[q] = '1';
        }

        if (q < n - 1)
        {
            if (s[q] == s[q + 1])
            {
                len++;
            }
            else
            {
                len--;
            }
        }

        if (q > 0)
        {
            if (s[q] == s[q - 1])
            {
                len--;
            }
            else
            {
                len--;
            }
        }
        cout << len << endl;
    }
    return 0;
}
