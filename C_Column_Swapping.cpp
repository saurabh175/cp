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
    int n, m;
    cin >> n >> m;
    int x;
    vvi v(n + 1, vi(m + 1));
    fo(i, 1, n + 1)
    {
        fo(j, 1, m + 1)
        {
            cin >> v[i][j];
        }
    }
    bool ok = 1;
    int cnt = 1;
    int c1 = 1, c2 = 1;
    fo(i, 1, n + 1)
    {
        fo(j, 1, m)
        {
            if (v[i][j] <= v[i][j + 1])
            {
                continue;
            }
            else
            {
                if (cnt == 1)
                {
                    c1 = j;
                    int k = j;
                    while (k >= 2)
                    {
                        if (v[i][k] == v[i][k - 1])
                        {
                            k--;
                        }
                        else
                        {
                            break;
                        }
                    }
                    c1 = k;
                    cnt++;
                }
                int k = j + 1;

                while (k <= m)
                {
                    if (v[i][k] == v[i][k + 1])
                    {
                        k++;
                    }
                    else
                    {
                        break;
                    }
                }
                c2 = k;
            }
        }
    }
    fo(i, 1, n + 1)
    {

        swap(v[i][c1], v[i][c2]);
    }
    fo(i, 1, n + 1)
    {
        fo(j, 1, m)
        {
            if (v[i][j] > v[i][j + 1])
            {
                ok = 0;
                break;
            }
        }
    }
    if (ok == 0)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << c1 << " " << c2 << endl;
    }
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
