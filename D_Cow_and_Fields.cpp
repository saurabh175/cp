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
int N = 300500;
vi fact(N, 1);
vi invFact(N, 1);
int fast_pow(int a, int p)
{
    int res = 1;
    while (p)
    {
        if (p % 2 == 0)
        {
            a = (a * a) % mod;
            p /= 2;
        }
        else
        {
            res = (res * a) % mod;
            p--;
        }
    }
    return res;
}
void fact1()
{
    fact[0] = invFact[0] = 1;
    for (int i = 1; i < N; i++)
    {
        fact[i] = (fact[i - 1] * i) % mod;
        invFact[i] = fast_pow(fact[i], mod - 2);
    }
}
int C(int n, int k)
{
    if (k > n)
    {
        return 0;
    }
    return fact[n] * invFact[k] % mod * invFact[n - k] % mod;
}
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
int power(int x, int y, int m)
{
    int temp;
    if (y == 0)
        return 1;
    temp = (power(x, y / 2, m) % m);
    if (y % 2 == 0)
        return (temp * temp) % m;
    else
        return (((x * temp) % mod) * (temp % mod)) % m;
};
long long binpow(long long a, long long b)
{
    long long res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}
string cnt_string(int n)
{
    string s;
    while (n)
    {
        s.pb((n % 10) + '0');
        n /= 10;
    }
    int i = 0, j = s.sz - 1;
    while (i < j)
    {
        swap(s[i], s[j]);
        i++, j--;
    }
    return s;
}
vector<bool> vis(1e6);
vvi g;
int ans;
int n, m, k;
void dfs(int u)
{
    vis[u] = true;
    for (auto v : g[u])
    {
        if (!vis[v])
        {
            dfs(v);
        }
    }
}
vi bfs(int sourse)
{
    queue<int> q;
    vi dist(n + 1, inf);
    dist[sourse] = 0;
    q.push(sourse);
    fo(i, 1, n + 1)
    {
        vis[i] = 0;
    }
    vis[sourse] = 1;
    while (q.sz)
    {
        int curr = q.front();
        q.pop();
        for (auto x : g[curr])
        {
            if (vis[x])
                continue;
            dist[x] = dist[curr] + 1;
            q.push(x);
            vis[x] = 1;
        }
    }
    return dist;
}
void solve()
{
    cin >> n >> m >> k;
    vi v(k);
    g.resize(n + 1);
    fo(i, 1, n + 1)
    {
        vis[i] = 0;
    }
    fo(i, 0, k)
    {
        cin >> v[i];
    }
    fo(i, 0, m)
    {
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    vi dist_1, dist_2;
    dist_1 = bfs(1);
    dist_2 = bfs(n);
    vp diff;
    fo(i, 0, k)
    {
        diff.pb({(dist_1[v[i]] - dist_2[v[i]]), v[i]});
    }
    sort(all(diff));

    vi max_suff(k);
    max_suff[k - 1] = dist_2[diff[k - 1].ss];
    rfo(i, 0, k - 1)
    {
        max_suff[i] = max(dist_2[diff[i].ss], max_suff[i + 1]);
    }

    int ans = 0;
    int curr = 0;
    fo(i, 0, k - 1)
    {
        int curr = min(dist_1[n], (dist_1[diff[i].ss] + (int)1 + max_suff[i + 1]));
        ans = max(ans, curr);
    }
    cout << ans << endl;
}
int32_t main()
{
    fast;
    int t = 1;
    // cin >> t;
    fo(i, 1, t + 1)
    {
        solve();
    }
    return 0;
}
