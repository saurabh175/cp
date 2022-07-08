#include <bits/stdc++.h>
using namespace std;
#define int long long
#define vi vector<int>
#define vvi vector<vector<int>>
#define vs vector<string>
#define set set<int>
#define sets set<string>
#define vp vector<pair<int, int>>
#define map map<int, int>
#define umap unordered_map<int>
#define pi (3.141592653589)
#define mod 1000000007
#define float double
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define sz size()
#define len length()
#define inf 1e18
#define all(c) c.begin(), c.end()
#define min3(a, b, c) min(c, min(a, b))
#define min4(a, b, c, d) min(d, min(c, min(a, b)))
#define max3(a, b, c) max(c, max(a, b))
#define max4(a, b, c, d) max(d, max(c, max(a, b)))
#define rfo(i, j, n) for (int i = n - 1; i >= j; i--)
#define fo(i, j, n) for (int i = j; i < n; i++)
#define fast ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

bool isPrime(int n)
{
    if (n == 1)
        return false;
    if (n == 2)
        return true;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

int GCD(int a, int b)
{
    while (b)
    {
        a %= b;
        swap(a, b);
    }
    return a;
}
int LCM(int a, int b)
{
    return (a * b) / GCD(a, b);
}
vector<bool> vis(1e6);
vvi g;
int ans, n, m;
bool ok = true;
bool dfs(int u)
{
    vis[u] = true;
    for (auto v : g[u])
    {
        if (!vis[v])
        {
            if (!dfs(v))
                return false;
        }
    }
    return true;
};
void solve()
{
    int n;
    cin >> n;
    vi v(n + 1);
    map m;
    fo(i, 2, n + 1)
    {
        cin >> v[i];
        m[v[i]]++;
    }
    string s;
    cin >> s;
    vi leaf;
    fo(i, 2, n + 1)
    {
        if (m[i] == 0)
        {
            leaf.pb(i);
        }
    }
    vvi ans(n + 1, vi(3, 0));
    for (auto x : leaf)
    {
        int y = v[x];
        int w = 0, b = 0;

        if (s[x - 1] == 'W')
        {

            if (!ans[x][2])
                w++;
            ans[x][0] += w;
            ans[x][1] += b;
            ans[x][2] = 1;
        }
        else if (s[x - 1] == 'B')
        {
            if (!ans[x][2])
                b++;
            ans[x][1] += b;
            ans[x][0] += w;
            ans[x][2] = 1;
        }
        while (y)
        {
            if (s[y - 1] == 'W')
            {
                if (!ans[y][2])
                    w++;
                ans[y][0] += w;
                ans[y][1] += b;
                ans[y][2] = 1;
            }
            else if (s[y - 1] == 'B')
            {
                if (!ans[y][2])
                    b++;
                ans[y][1] += b;
                ans[y][0] += w;
                ans[y][2] = 1;
            }

            y = v[y];
        }
    }
    int cnt = 0;
    fo(i, 1, n + 1)
    {

        if (ans[i][0] == ans[i][1])
        {
           // cout << i << " is balanced " << endl;
            cnt++;
        }
    }
    cout << cnt << endl;
}
int32_t main()
{
    int t = 1;
    cin >> t;
    fo(i, 1, t + 1)
    {
        solve();
    }
    return 0;
}
