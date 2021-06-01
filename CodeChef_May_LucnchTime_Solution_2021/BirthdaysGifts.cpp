// LunchTtime Sol.
#include <bits/stdc++.h>
using namespace std;
#define ll long long int


int main(){

    ll n,k;
    cin >> n >> k;
    
    vector<ll> arr(n);
    for(auto &x : arr){
        cin >> x;
    }
    
    ll s1 = 0, s2 = 0;

    sort(arr.begin() , arr.end());

    while (k--)
    {
        /* code */
        s1 += arr.back(); arr.pop_back();
        s2 += arr.back(); arr.pop_back();
    }
    s2 += arr.back();
    cout << max(s1,s2) <<endl ;
    
    
}