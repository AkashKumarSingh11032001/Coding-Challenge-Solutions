#include <bits/stdc++.h>
using namespace std;


int main(){

    int t;
    cin >> t;

    while (t--)
    {
        /* code */
        int a,b,c,d;
        cin >> a >>b >> c >>d;

        int water = (int)c/a ;
        int pulp = (int)d/b;
        int res = water + pulp;

        cout << res <<endl;

    }
    return 0;
    
}