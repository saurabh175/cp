#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
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
    string s;
    cin >> s;
    int x;
    cin >> x;
    int h = x / 60;
    int m = x % 60;
    string hs, ms;
    int ans = 0;
    if (h >= 10)
    {
        hs = to_string(h);
    }
    else
        hs += "0" + to_string(h);
    if (m >= 10)
    {
        ms = to_string(m);
    }
    else
        ms += "0" + to_string(m);
    string temp = s;
    while (1)
    {
        string s1 = temp.substr(0, 2);
        string s2 = temp.substr(3, 2);
        int n1 = stoi(s1);
        int n2 = stoi(s2);
        n1 += h;
        n2 += m;
        if (n2 >= 60)
        {
            n2 -= 60;
            n1 += 1;
        }
        if (n1 >= 24)
        {
            n1 -= 24;
        }
        string s3, s4;
        if (n2 < 10)
        {
            s3 += "0" + to_string(n2);
            reverse(all(s3));
        }
        else
        {
            s3 = to_string(n2);
            reverse(all(s3));
        }
        if (n1 < 10)
        {
            s4 += "0" + to_string(n1);
        }
        else
        {
            s4 = to_string(n1);
        }
        if (s3 == s4)
        {
            ans++;
        }
        reverse(all(s3));
        temp = s4 + ":" + s3;
        if (s4 == s.substr(0, 2) && s3 == s.substr(3, 2))
        {
            break;
        }
    }
    cout << ans << endl;
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
