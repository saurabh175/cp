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
     if (y % 2 == 0) return (temp * temp) % m;
    else return (((x * temp) % mod) * (temp % mod)) % m;
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
    string s;
    cin >> s;
    int d = 0, l = 0, u = 0, s1 = 0, dvalue = 1;
    char chl = 'a';
    char chu = 'A';
    char sch = '@';
    for (auto x : s)
    {
        if ((int)x >= 48 && x <= 57)
        {
            d = 1;
            dvalue = x - '0';
        }
        else if ((int)x >= 65 && x <= 90)
        {
            u = 1;
            chu = x;
        }
        else if ((int)x >= 97 && x <= 122)
        {
            l = 1;
            chl = x;
        }
        else if ((int)x == 64 || (int)x == 42 || (int)x == 38 || (int)x == 35)
        {
            s1 = 1;
            sch = x;
        }
    }
    if (d == 0)
    {
        s += dvalue + '0';
    }
    if (u == 0)
    {
        s += chu;
    }
    if (l == 0)
    {
        s += chl;
    }
    if (s1 == 0)
    {
        s += sch;
    }
    if (s.sz < 7)
    {
        int x = s[0];
        string s2(7 - s.sz, x);
        s += s2;
    }
    cout << s << endl;
}
int32_t main()
{
    fast;
    int t = 1;
    cin >> t;
    fo(i, 1, t + 1)
    {
        cout << "Case #" << i << ": ";
        solve();
    }
    return 0;
}
