#include <bits/stdc++.h>
using namespace std;
#define int long long
#define vi vector<int>
#define vc vector<char>
#define vvi vector<vector<int>>
#define vvc vector<vector<char>>
#define vvs vector<vector<string>>
#define vs vector<string>
#define seti set<int>
#define setc set<char>
#define sets set<string>
#define vp vector<pair<int, int>>
#define mapi map<int, int>
#define mapc map<char, int>
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
bool comp(pair<int, int> &p1, pair<int, int> &p2)
{
    return p1.ff > p2.ff;
}
vector<bool> vis(1e5 + 1);
vvi g;
int ans;
int n, m;
void dfs(int u)
{
    vis[u] = 1;
    for (auto v : g[u])
    {
        if (!vis[v])
        {
            dfs(v);
        }
    }
};
void solve()
{
    cin >> n;
    g.resize(n + 1);
    fo(i, 1, n + 1) vis[i] = 0;
    seti s;
    vp v(n + 1);
    fo(i, 1, n + 1)
    {
        cin >> v[i].ff;
        v[i].ss = i;
    }
    sort(all(v), comp);
    fo(i, 0, n)
    {
        auto it = s.end();
        if (s.sz > 0)
        {
            it--;
        }
        if (s.lower_bound(v[i].ss) != s.end() || *(it) < v[i].ss)
        {
            if (s.lower_bound(v[i].ss) == s.end())
            {
                for (auto it1 = s.begin(); it1 != s.end(); it1++)
                {
                    g[*it1].pb(v[i].ss);
                    g[v[i].ss].pb(*it1);
                }
            }
            else
            {
                it = s.lower_bound(v[i].ss);
                for (auto it1 = s.begin(); it1 != it; it1++)
                {
                    g[*it1].pb(v[i].ss);
                    g[v[i].ss].pb(*it1);
                }
            }
            s.insert(v[i].ss);
        }
        else
        {
            s.insert(v[i].ss);
        }
    }
    ans = 0;
    fo(i, 1, n + 1)
    {
        if (!vis[i])
        {
            dfs(i);
            ans++;
        }
    }
    cout << ans << endl;
    g.clear();
    s.clear();
    vis.clear();
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
