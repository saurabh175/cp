#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
const ll mod = 1e9 + 7, inf = 1e18;
#define UNVISITED -1
#define IMPORTANT 1
#define pb push_back

int main()
{
   
    int n, k, d;
    cin >> n >> k >> d;
    vvvi adj(n + 1); // because we need to store the indices of each edge
   // vi dist(n + 1, 1e9);
    vb vis(n + 1, false);
    vi colour(n, UNVISITED);
    queue<int> q;

    for (int i = 1; i <= k; i++)
    {
        int ps;
        cin >> ps;
        q.push(ps);
        vis[ps] = 1;
       // dist[ps] = 0;
    }
    for (int i = 1; i <= n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].pb({v, i});
        adj[v].pb({u, i});
    }
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (auto val : adj[u])
        {
            int v = val[0], index = val[1];
            if (!vis[v])
            {
                vis[v] = 1;
                colour[index] = IMPORTANT;
                q.push(v);
            }
        }
    }
    vi ans;
    for (int i = 1; i <= n - 1; i++)
        if (colour[i] == UNVISITED)
            ans.pb(i);
    cout << ans.size() << '\n';
    for (int edge : ans)
        cout << edge << " ";
    return 0;
}