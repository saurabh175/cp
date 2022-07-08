#include <bits/stdc++.h>
using namespace std;
#define int long long
#define vi vector<int>
#define vvi vector<vector<int>>
#define vs vector<string>
#define set set<int>
#define sets set<string>
#define vp vector<pair<int, int>>
#define map map<int, int>
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
int value = 32768;
vvi dp(value + 2, vi(16, -1));
bool sol(int n, int k)
{

    if (k == 15)
    {
        return true;
    }
    if (k == 0)
    {
        if (n == 0)
            return true;
        else
            return false;
    }
    if (dp[n][k] != -1)
    {
        return dp[n][k];
    }
    bool res = false;
    if (sol((n + 1) % 32768, k - 1) || sol((n * 2) % 32768, k - 1))
        res = true;
    return dp[n][k] = res;
}

void solve(int n)
{

    int ans = INT_MAX, temp;
    fo(i, 0, 16)
    {
        if (sol(n, i))
        {
            cout << i<<" ";
            break;
        }
        else
            continue;
        temp = n + i;
        if (temp % 32768 == 0)
        {
            ans = min(ans, i);
            continue;
        }
        fo(j, 1, 16)
        {
            temp = (temp * 2) % 32768;
            if (temp == 0)
            {
                ans = min(ans, i + j);
                break;
            }
        }
    }
   // cout << ans << " ";
}
int32_t main()
{
    int t = 1, n;
    cin >> t;
    fo(i, 1, t + 1)
    {
        cin >> n;
        solve(n);
    }
    return 0;
}
