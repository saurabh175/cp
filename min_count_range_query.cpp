#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>     // Including tree_order_statistics_node_update
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
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
vp tre;
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

pair<int, int> f(int si, int sl, int sr, int ql, int qr, int v)
{
    if (ql <= sl && sr <= qr)
    {
        if (v != -1)
        {
            tre[si].ff = v;
        }
        return {tre[si].ff, tre[si].ss};
    }
    if (sr < ql || sl > qr)
    {
        return {inf, 0};
    }
    int mid = sl + (sr - sl) / 2;
    pair<int, int> l = f(2 * si, sl, mid, ql, qr, v);
    pair<int, int> r = f(2 * si + 1, mid + 1, sr, ql, qr, v);
    if (tre[2 * si].ff < tre[2 * si + 1].ff)
    {
        tre[si].ff = tre[2 * si].ff;
        tre[si].ss = tre[2 * si].ss;
    }
    else if (tre[2 * si].ff > tre[2 * si + 1].ff)
    {
        tre[si].ff = tre[2 * si + 1].ff;
        tre[si].ss = tre[2 * si + 1].ss;
    }
    else
    {
        tre[si].ff = tre[2 * si].ff;
        tre[si].ss = tre[2 * si].ss + tre[2 * si + 1].ss;
    }
    if (l.ff < r.ff)
    {
        return {l.ff, l.ss};
    }
    else if (l.ff > r.ff)
    {
        return {r.ff, r.ss};
    }
    else
    {
        return {l.ff, (l.ss + r.ss)};
    }
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
        num.pb(inf);
    }
    tre.resize(2 * n, {inf, 1});
    for (int i = 0; i < n; i++)
    {
        tre[i + n].ff = num[i];
        tre[i + n].ss = 1;
    }
    for (int i = n - 1; i >= 1; i--)
    {
        if (tre[2 * i].ff < tre[2 * i + 1].ff)
        {
            tre[i].ff = tre[2 * i].ff;
            tre[i].ss = tre[2 * i].ss;
        }
        else if (tre[2 * i].ff > tre[2 * i + 1].ff)
        {
            tre[i].ff = tre[2 * i + 1].ff;
            tre[i].ss = tre[2 * i + 1].ss;
        }
        else
        {
            tre[i].ff = tre[2 * i].ff;
            tre[i].ss = tre[2 * i].ss + tre[2 * i + 1].ss;
        }
    }
    // for (auto x : tre)
    // {

    //     cout << x.ff << " " << x.ss << endl;
    // }
    while (q--)
    {
        int t, a, b;
        cin >> t;
        if (t == 1)
        {
            cin >> a >> b;
            f(1, 0, n - 1, a, a, b);
        }
        else
        {
            cin >> a >> b;
            b--;
            pair<int, int> cnt = f(1, 0, n - 1, a, b, -1);
            cout << cnt.ff << " " << cnt.ss << endl;
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
