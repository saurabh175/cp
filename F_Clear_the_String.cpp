#include <bits/stdc++.h>
using namespace std;
#define int long long
#define vi vector<int>
#define vvi vector<vector<int>>
#define vs vector<string>
#define set set<int>
#define sets set<string>
#define vp vector<pair<int, int>>
#define mapi map<int, int>
#define umap unordered_map<int>
#define pi (3.141592653589)
#define mod 1000000007
#define float double
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define sz size()
#define len length()
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
bool is_palindrom(string s)
{
    string s1 = s;
    reverse(all(s));
    if (s1 == s)
    {
        return true;
    }
    else
        return false;
}
void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    map<char, int> m;
    for (auto x : s)
    {
        m[x]++;
    }
    vvi dp(n + 2, vi(n + 2));
    rfo(i, 1, n + 1)
    {
        fo(j, i, n + 1)
        {
            if (i == j)
            {
                dp[i][j] = 1;
                continue;
            }
            dp[i][j] = 1 + dp[i + 1][j];
            if (s[i - 1] == s[i])
            {
                dp[i][j] = min(dp[i][j], 1 + dp[i + 2][j]);
            }
            fo(k, i + 2, j + 1)
            {
                if (s[k - 1] == s[i - 1])
                {
                    dp[i][j] = min(dp[i][j], dp[i + 1][k] + dp[k + 1][j]);
                }
            }
        }
    }
        cout << dp[1][n] << endl;
}
int32_t main()
{
    int t = 1;
    // cin >> t;
    fo(i, 1, t + 1)
    {
        solve();
    }
    return 0;
}
