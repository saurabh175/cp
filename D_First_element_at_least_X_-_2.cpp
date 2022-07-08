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
int n, m;
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
vector<long long> tree;
int f(int si, int sl, int sr, int ql, int qr, int v)
{
    if (ql <= sl && sr <= qr)
    {
        if (v != -1)
        {
            tree[si] = v;
        }
        return tree[si];
    }
    if (sr < ql || sl > qr)
    {
        return 0;
    }
    int mid = sl + (sr - sl) / 2;
    long long maxs = max(f(2 * si, sl, mid, ql, qr, v), f(2 * si + 1, mid + 1, sr, ql, qr, v));
    // tree[si] =tree[2 * si] +tree[2 * si + 1];
    tree[si] = max(tree[2 * si], tree[2 * si + 1]);
    return maxs;
}
bool ok = 0;
int search_least(int si, int sl, int sr, int k, int b)
{
    if (tree[1] < k)
    {
        ans = -1;
        return 1;
    }
    if (sr < b)
    {
        return 0;
    }
    if (sl == sr)
    {
        if (tree[si] >= k)
        {
            ans = sl;
            return 1;
        }
        else
            return 0;
    }
    int mid = sl + (sr - sl) / 2;
    if (tree[2 * si] >= k)
    {
        if (search_least(2 * si, sl, mid, k, b))
            return 1;
    }
    if (search_least(2 * si + 1, mid + 1, sr, k, b))
        return 1;
    return 0;
}
void solve()
{
    int q;
    cin >> n >> q;
    vi num(n);
    fo(i, 0, n)
    {
        cin >> num[i];
    }
    while (__builtin_popcount(n) != 1)
    {
        n++;
        num.pb(0);
    }
    tree.resize(2 * n, 0);
    for (int i = 0; i < n; i++)
    {
        tree[i + n] = num[i];
    }
    for (int i = n - 1; i >= 1; i--)
    {
        tree[i] = max(tree[2 * i], tree[2 * i + 1]);
    }
    while (q--)
    {
        int t, a, b;
        cin >> t;
        ans = -1;
        ok = 0;
        if (t == 1)
        {
            cin >> a >> b;
            f(1, 0, n - 1, a, a, b);
        }
        else
        {
            cin >> a >> b;
            search_least(1, 0, n - 1, a, b);
            cout << ans << endl;
        }
    }
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