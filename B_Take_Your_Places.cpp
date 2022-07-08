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
    int n;
    cin >> n;
    vi v(n);
    int e = 0, o = 0;
    fo(i, 0, n)
    {
        cin >> v[i];
        if (v[i] % 2 == 0)
            e++;
        else
            o++;
    }
    if (n == 1)
    {
        cout << 0 << endl;
        return;
    }
    if (abs(e - o) > 1)
    {
        cout << -1 << endl;
        return;
    }
    else
    {
        int i = 0, j = 0;
        int ans = inf, ans1 = inf;
        int k = 0;
        vi v1(n);
        vi v2(n);
        fo(i, 0, n)
        {
            if (i % 2 == 0)
                v1[i] = 0;
            else
                v1[i] = 1;
        }
        fo(i, 0, n)
        {
            if (i % 2 == 0)
                v2[i] = 1;
            else
                v2[i] = 0;
        }
        bool ok = 0, ok1 = 0;

        vi temp = v;
        int curr = 0;
        while (i < n && j < n && e >= o)
        {
            ok1 = 1;
            if (i == j)
                ok = 0;
            if ((v[i] % 2) == v1[i])
            {
                i++;
                if (ok == 0)
                    j++;
                continue;
            }
            else
            {
                ok = 1;
                j++;
                while (j < n)
                {

                    if ((v[j] % 2) == v1[i])
                    {
                        swap(v[i], v[j]);
                        break;
                    }

                    j++;
                }
                curr += (j - i);
            }
            i++;
        }
        i = 0, j = 0;
        ok = 0;
        v = temp;
        if (ok1)
            ans = curr;
        curr = 0;
        ok1 = 0;
        while (i < n && j < n && o >= e)
        {
            ok1 = 1;
            if (i == j)
                ok = 0;
            if ((v[i] % 2) == v2[i])
            {
                i++;
                if (ok == 0)
                    j++;
                continue;
            }
            else
            {
                ok = 1;
                j++;
                while (j < n)
                {

                    if ((v[j] % 2) == v2[i])
                    {
                        swap(v[i], v[j]);
                        break;
                    }
                    j++;
                }
                curr += (j - i);
            }
            i++;
        }
        if (ok1)
            ans1 = curr;
        // cout << ans1 << endl;
        cout << max(min(ans, ans1), (int)0) << endl;
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
