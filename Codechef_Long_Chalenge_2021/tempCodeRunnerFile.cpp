#include <bits/stdc++.h>
using namespace std;

long long int ipow(long long int base, long long int exp)
{
    long long int result = 1;
    for (;;)
    {
        if (exp & 1)
            result *= base;
        exp >>= 1;
        if (!exp)
            break;
        base *= base;
    }

    return result;
}

int main()
{

    long long int t;
    cin >> t;
    long long int N, M;

    while (t--)
    {
        /* code */
        cin >> N >> M;

        long long int res = ipow(2, N) % 1000000007 -1;
        long long int sol = ipow(res, M) % 1000000007;

        cout << sol << endl;
    }
}