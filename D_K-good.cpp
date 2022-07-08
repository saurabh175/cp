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
    long long n;
    cin >> n;
    int ok = 0;
    int k = 1, p = n;
    while (n)
    {
        k++;
        n /= 2;
    }
    int y = (k * (k + 1)) / 2;
    int y1 = ((k + 1) * (k + 2)) / 2;
    int y2 = (k * (k - 1)) / 2;
    if (p <= 2)
    {
        cout << -1 << endl;
        return;
    }
    if (p % 2 != 0)
    {
        cout << 2 << endl;
        return;
    }
    if (p % 3 == 0)
    {
        cout << 3 << endl;
        return;
    }
    int i = 2;
    int z = 0, m;
    while (p - z >= 0 && i < 1000000000)
    {
        m = ((i - 1) * i) % mod;
        z = m / 2;
        if ((p - z) >= 0 && (p - z) % i == 0)
        {
            cout << i << endl;
            return;
        }
        i++;
    }
    if (y == p || y + k == p)
    {
        cout << k << endl;
    }
    else if (y1 == p || y1 + k + 1 == p)
    {
        cout << k + 1 << endl;
    }
    else if (y2 == p || y2 + k - 1 == p)
    {
        cout << k - 1 << endl;
    }
    else
    {
        cout << -1 << endl;
    }
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
