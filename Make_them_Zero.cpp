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
    if (y == 0)
        return 1;
    else if (y % 2 == 0)
        return ((power(x, y / 2, m) % m) * (power(x, y / 2, m) % m)) % m;
    else
        return (((x * ((power(x, y / 2, m) % m))) % mod) * (power(x, y / 2, m) % m) % mod) % m;
};
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
    int n;
    cin >> n;
    vi v(n);
    vi v2;
    seti s, s1;
    bool ok = 0;
    int sum = 0;
    fo(i, 0, n)
    {
        cin >> v[i];
        if (v[i] != 0)
        {
            if (ceil(log2(v[i])) == floor(log2(v[i])))
            {
                s.insert(floor(log2(v[i])));
            }
            else
            {
                if (s.find(floor(log2(v[i]))) == s.end())
                {
                    s.insert(floor(log2(v[i])));
                }
                int rem = v[i] - (int)pow(2, floor(log2(v[i])));
                while (rem)
                {
                    int x = floor(log2(rem));
                    if (s.find(x) == s.end())
                    {
                        s.insert(x);
                    }
                    rem -= (int)pow(2, floor(log2(rem)));
                }
            }
        }
    }
    //   cout << s.sz << " " << s1.sz << endl;
    int ans = s.sz;
    cout << ans << endl;
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
