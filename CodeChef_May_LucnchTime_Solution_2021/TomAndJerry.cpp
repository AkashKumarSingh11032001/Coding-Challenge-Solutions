// LunchTtime Sol.
#include <bits/stdc++.h>
using namespace std;


int main(){

    int a,b,c,d,k;
    cin >> a >>b >>c >>d >>k;

    int dis = abs(a-c) + abs(b-d);
    if(k >= dis && k%2 == dis%2){
        cout << "Yes" <<endl;
    }
    else {
        cout << "No" <<endl;
    }

    return 0;
}