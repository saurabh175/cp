#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
//#define int long long
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
    string str;
    cin >> str;
    string s = str;
    int n = s.size();
    vector<vector<int>> dp(1002, vector<int>(1002, 0));
    for (int i = 1; i <= n; i++)
    {
        dp[i][i] = 1;
    }
    int cnt = 0;
    char ch;
    bool ok = 0;
    for (int i = n-1; i > 0; i--)
    {
        for (int j = i+1; j <= n; j++)
        {
            if (s[i - 1] == s[j - 1])
            {
                cnt++;
                if (cnt == 1)
                {
                    ch = s[i - 1];
                    cout << ch << " ";
                    cout << cnt << endl;
                }
                if (cnt == 2)
                {
                    cout << s[i - 1] <<" ";
                    cout << cnt << endl;
                    if (ch == s[i - 1])
                        ok = 1;
                }
                if (i != j)
                {
                    dp[i][j] = 2 + dp[i + 1][j - 1];
                }
                else
                    dp[i][j] = 1 + dp[i + 1][j - 1];
            }
            else
                dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
        }
    }
    cout << ok << endl;
    if (ok == 1)
        cout << max(0, dp[1][n] - 1);
    else
        cout << max(0, dp[1][n] - 2);
}

// string str1, str2;
// cin >> str1 >> str2;
// vector<vector<int>> dp(1002, vector<int>(1002, 0));
// int n = str1.size();
// int m = str2.size();
// for (int i = 1; i <= n; i++)
// {
//     for (int j = 1; j <= m; j++)
//     {
//         if (str1[i - 1] == str2[j - 1])
//         {
//             dp[i][j] = 1 + dp[i - 1][j - 1];
//         }
//         else
//             dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
//     }
// }
// vector<char> ans;
// int i = n, j = m;
// while (i > 0 && j > 0)
// {
//     if (dp[i][j] == dp[i - 1][j])
//     {
//         i--;
//     }
//     else if (dp[i][j] == dp[i][j - 1])
//         j--;
//     else
//     {
//         ans.push_back(str1[i - 1]);
//         i--, j--;
//     }
// }
// reverse(ans.begin(), ans.end());
// for (auto x : ans)
// {
//     cout << x << " ";
// }
// cout << endl;
// i = 0, j = 0;
// int k = 0;
// int leng = ans.sz;
// cout << ans.sz << endl;
// string s;
// cout << str1 << endl;
// cout << str2 << endl;
// while (i < n && j < m && k < leng)
// {
//     if (str1[i] == str2[j] && str1[i] == ans[k] && str1[i] != ' ')
//     {

//         s.push_back(str1[i]);
//         i++;
//         j++;
//         k++;
//         cout << ans[k - 1] << " ";
//     }
//   else  if (str1[i] != ans[k] && str1[i] != ' ')
//     {
//         s.push_back(str1[i]);
//         cout << str1[i] << " ";
//         i++;
//     }
//    else if (str2[j] != ans[k] && str1[i] != ' ')
//     {
//         s.push_back(str2[j]);
//         cout << str2[j] << " ";
//         j++;
//     }
// }
// while (i < n)
// {
//     if (str1[i] != ' ')
//     {
//         cout << str1[i] << " ";
//         s.push_back(str1[i]);
//         i++;
//     }
// }
// while (j < m)
// {
//     if (str2[j] != ' ')
//     {
//         cout << str2[j] << " ";
//         s.push_back(str2[j]);
//         j++;
//     }
// }

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
