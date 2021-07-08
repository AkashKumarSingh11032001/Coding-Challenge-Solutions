#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MOD 1000000007
// #define all(z) z.begin(),z.end()
using ll = long long int;

using namespace std;

ll my_pow(ll a, ll b) {
 static ll mod = 1000000007;
 if (b == 0) return 1;
 if (b == 1) return a;

 if (b % 2 == 0) {
  ll ans = my_pow(a, b / 2);
  return (ans * ans) % mod;
 }
 else {
  ll ans = my_pow(a, ((b - 1) / 2));
  return ((a * ans) % mod * ans) % mod;
 }
}

int main() {
 fast;
 int test;
 cin >> test;
 while (test--) {

  ll N, M, res;
  cin >> N >> M;

  res = my_pow(2 , N) - 1;

  cout << my_pow(res, M) << endl;

 }

 return 0;
}
