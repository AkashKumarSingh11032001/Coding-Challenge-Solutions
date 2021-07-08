#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vector<int>>
int goingfar(int node, vvi &G, int n)
{
    vector<bool> done(n + 1, false);
    int fd = -1, far;
    done[node] = true;
    queue<pair<int, int>> qu;
    qu.push({node, 0});
    while (qu.size())
    {
        auto pi = qu.front();
        qu.pop();
        int nod = pi.first, dis = pi.second;
        if (fd < dis)
            fd = dis, far = nod;
        for (auto xyz : G[nod])
        {
            if (done[xyz])
                continue;
            done[xyz] = true;
            qu.push({xyz, dis + 1});
        }
    }
    return far;
}
void dfs(int nod, int par, vvi &G, vi &H, vi &li, int cur)
{
    bool isleaf = true;
    int mx = 0;
    for (auto xyz : G[nod])
        if (xyz != par)
        {
            isleaf = false;
            mx = max(mx, H[xyz]);
        }
    if (isleaf)
    {
        li.push_back(cur);
        return;
    }
    int c = 0;
    for (auto xyz : G[nod])
    {
        if (xyz == par)
            continue;
        if (H[xyz] == mx && c == 0)
        {
            dfs(xyz, nod, G, H, li, cur + 1);
            c++;
        }
        else
            dfs(xyz, nod, G, H, li, 1);
    }
}
void constheight(int nod, int par, vvi &G, vi &H)
{
    bool isleaf = true;
    for (auto xyz : G[nod])
    {
        if (xyz == par)
            continue;
        isleaf = false;
        constheight(xyz, nod, G, H);
        H[nod] = max(H[nod], 1 + H[xyz]);
    }
    if (isleaf)
        H[nod] = 1;
}
void sepratebylines(int nod, int par, vvi &G, vi &li, int n)
{
    vector<int> H(n + 1, 0);
    constheight(nod, par, G, H);
    dfs(nod, par, G, H, li, 1);
}
int givemysolution(vvi &gr, int n, int k)
{
    if (k == 1)
        return 1;
    int u = goingfar(1, gr, n);
    vector<int> li;
    sepratebylines(u, 0, gr, li, n);
    sort(li.rbegin(), li.rend());
    int size = 1, total = 0, i = 0;
    while (total < k)
    {
        size++;
        total += li[i++];
    }
    return size;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    int n, k;
    int u, v;
    while (t--)
    {
        cin >> n >> k;
        vvi gr(n + 1);
        for (int i = 1; i < n; i++)
        {
            cin >> u >> v;
            gr[u].push_back(v);
            gr[v].push_back(u);
        }
        cout << givemysolution(gr, n, k) << "\n";
    }
    return 0;
}