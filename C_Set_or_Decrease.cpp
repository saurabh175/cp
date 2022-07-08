#include <bits/stdc++.h>
using namespace std;
#define int long long
#define vll vector<int>
#define pi (3.141592653589)
#define mod 1000000007
#define float double
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
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
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    fo (i, 0, n)
    {
        cin >> a[i];
    }
    sort(all(a));
    vector<int> pre(n + 1);
    for (int i = 1; i < n; i++)
        pre[i] = pre[i - 1] + a[i];

    int ans = INT_MAX;
    for (int i = n - 1; i >= 0; i--)
    {
        int sum = pre[i];
        int cnt = n - i;
        int req = k - sum;
        req = req / cnt;

        for (int x = req - 5; x <= req + 5; x++)
        {
            if (sum + cnt * x > k)
                continue;
            int curr = 0;
            if (x <= a[0])
                curr += a[0] - x;
            curr += cnt - 1;
            ans = min(ans, curr);
        }
    }
    cout << ans << endl;
}
int32_t main()
{
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
