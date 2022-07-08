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
void solve()
{
    int w, h;
    cin >> w >> h;
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    int l = x1, r = abs(w - x2);
    int d1 = y1, d2 = abs(h - y2);
    int x, y;
    cin >> x >> y;
    if (x > l + r && y > d1 + d2)
    {
        cout << -1 << endl;
    }
    else
    {
        int sum1 = l + r - x;
        int sum2 = d1 + d2 - y;
        int ans1 = inf, ans2 = inf;
        long double ans = 0;
        if (sum1 >= 0)
        {
            int l1 = max(x - x1, (int)0);
            if (l1 <= r)
            {
                ans1 = min(ans1, l1);
            }
            int l2 = max(x - w + x2, (int)0);
            if (l2 <= x)
            {
                ans1 = min(ans1, l2);
            }
        }
        if (sum2 >= 0)
        {
            int l1 = max(y - y1, (int)0);
            if (l1 <= d2)
            {
                ans2 = min(ans2, l1);
            }
            int l2 = max(y - h + y2, (int)0);
            if (l2 <= d1)
            {
                ans2 = min(ans2, l2);
            }
        }
        ans = min(ans1, ans2);
        cout << fixed << setprecision(7) << (double)ans << endl;
    }
}
int32_t main()
{
    fast;
    int t = 1;
    cin >> t;
    fo(i, 1, t + 1)
    {
        solve();
    }
    return 0;
}
