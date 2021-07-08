#include <bits/stdc++.h>
using namespace std;

int main()
{

    long long int t;
    cin >> t;

    while (t--)
    {
        /* code */
        long long int D, d, p, q;
        cin >> D >> d >> p >> q;
        long long int money = 0;
        long long int temp1;

        temp1 = D / d; // n

        if (temp1 % 2 == 0)
        {
            money += d * ((temp1 / 2) * (2 * p + (temp1 - 1) * q));
        }
        else
        {
            money += d * (temp1 * (p + ((temp1 - 1) / 2) * q));
        }
        money += (D % d) * (p + temp1 * q);
        cout << money << endl;
    }
}