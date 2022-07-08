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
void solve()
{
    int n;
    cin >> n;
    vi v(n);
    fo(i, 0, n)
    {
        cin >> v[i];
    }
    vi v1, v2;
    int ans = 0;
    fo(i, 0, n - 2)
    {
        fo(j, i + 1, n)
        {
            fo(k, j + 1, n)
            {
                if (v[k] > v[i])
                    v1.pb(k);
            }
            if (v1.sz == 0)
            {
                continue;
            }
            fo(k, v1[0] + 1, n)
            {
                if (v[k] < v[j])
                {
                    v2.pb(k);
                }
            }

            for (auto x : v1)
            {
                for (auto y : v2)
                {
                    if (y > x)
                        ans++;
                }
            }
            v1.clear();
            v2.clear();
        }
    }
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
