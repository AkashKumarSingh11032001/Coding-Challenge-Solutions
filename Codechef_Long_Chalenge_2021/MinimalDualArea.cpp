#include <bits/stdc++.h>
using namespace std;
#define int long long int
int32_t main() {
	// your code goes here
    ios_base::sync_with_stdio(false); 
	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        vector<pair<int, int>> x;
        vector<pair<int, int>> y;
        multiset<int> X;
        multiset<int> Y;
        for (int i = 0; i < n; ++i)
        {
            int a, b;
            cin >> a >> b;
            x.push_back({a, b});
            y.push_back({b, a});
            X.insert(a);
            Y.insert(b);
        }
        sort(x.begin(), x.end());
        sort(y.begin(), y.end());
        int hei_1 = 0;
        int hei_2 = 0;
        int h1Max = 0;
        int h1Min = LONG_MAX;
        int area = LONG_MAX;
        for (int i = 0; i < n - 1; ++i)
        {

            h1Max = max(h1Max, x[i].second);
            h1Min = min(h1Min, x[i].second);
            hei_1 = h1Max - h1Min;
            auto it = Y.find(x[i].second);
            Y.erase(it);
            hei_2 = *Y.rbegin() - *Y.begin();
            int newArea = (x[i].first - x[0].first) * hei_1 +
                          (x[n - 1].first - x[i + 1].first) * hei_2;
            area = min(area, newArea);
        }
        int w_1 = 0;
        int w_2 = 0;
        int w_1_Max = 0;
        int w_1_Min = LONG_MAX;
        for (int i = 0; i < n - 1; ++i)
        {
            w_1_Max = max(w_1_Max, y[i].second);
            w_1_Min = min(w_1_Min, y[i].second);
            w_1 = w_1_Max - w_1_Min;
            auto it = X.find(y[i].second);
            X.erase(it);
            w_2 = *X.rbegin() - *X.begin();
            int newArea = (y[i].first - y[0].first) * w_1 +
                          (y[n - 1].first - y[i + 1].first) * w_2;
            area = min(area, newArea);
        }
        if (area == LONG_MAX)
            area = 0;
        cout << area << endl;
    }
	return 0;
}