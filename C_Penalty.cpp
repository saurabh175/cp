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
    int n = 10;
    string s;
    cin >> s;
    vi prfa(n);
    vi prfb(n);
    prfa[n - 1] = 0;
    if (s[n - 1] == '1' || s[n - 1] == '?')
        prfb[n - 1] = 1;
    else
        prfb[n - 1] = 0;
    rfo(i, 0, n - 1)
    {
        if (i % 2 == 0)
        {
            if (s[i] == '1' || s[i] == '?')
                prfa[i] = prfa[i + 1] + 1;
            else
                prfa[i] = prfa[i + 1];
            prfb[i] = prfb[i + 1];
        }
        else
        {
            if (s[i] == '1' || s[i] == '?')
                prfb[i] = prfb[i + 1] + 1;
            else
                prfb[i] = prfb[i + 1];
            prfa[i] = prfa[i + 1];
        }
    }
    int r = 2;
    int ans1 = 0, ans2 = 0, ans3 = inf, ans4 = inf;
    fo(i, 0, n - 1)
    {

        int x = (n - i - 1) / 2;
        if (s[i] == '1' && i % 2 == 0)
        {
            ans1++;
        }
        if ((s[i] == '1' || s[i] == '?') && i % 2 == 1)
            ans2++;
        if (ans2 > ans1 + x)
        {
            if (ans2 > ans1 + prfa[i + 1])
            {
                ans3 = i + 1;
                break;
            }
        }
        //  cout << ans1 << " " << ans2 << " " << prfa[i + 1] << "" << ans3 << endl;
    }
    ans1 = 0, ans2 = 0;
    fo(i, 0, n - 1)
    {
        int x = (n - i) / 2;
        if ((s[i] == '1' || s[i] == '?') && i % 2 == 0)
        {
            ans1++;
        }
        if ((s[i] == '1') && i % 2 == 1)
            ans2++;
        if (ans1 > ans2 + x)
        {
            if (ans1 > ans2 + prfb[i + 1])
            {
                ans4 = i + 1;
                break;
            }
        }
        // cout << ans1 << " " << ans2 << " " << prfa[i + 1];
    }
    if (ans3 == inf && ans4 == inf)
    {
        cout << 10 << endl;
    }
    else
    {
        cout << min(ans3, ans4) << endl;
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
