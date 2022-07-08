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
    int n, x, y, d;
    cin >> n >> x >> y >> d;
    if (abs(y - x) % d == 0)
    {
        cout << abs(y - x) / d << endl;
    }
    else
    {
        int a = abs(y - 1) % d;
        int b = abs(n - y) % d;
        int ans1=INT_MAX, ans11, ans22, ans2=INT_MAX, ans3 = INT_MAX, ans4 = INT_MAX, ok = 0;
        if (a == 0)
        {
            ok = 1;
            if ((x - 1) % d == 0)
            {
                ans1 = abs(x - 1) / d + abs(y - 1) / d;
            }
            else
            {
                ans1 = abs(x - 1) / d + abs(y - 1) / d + 1;
            }
        }
        if (b == 0)
        {
            ok = 1;
            if (abs(n - x) % d == 0)
            {
                ans2 = abs(n - x) / d + abs(n - y) / d;
            }
            else
            {
                ans2 = abs(n - x) / d + abs(n - y) / d + 1;
            }
        }
      
        if (ok == 0)
        {
            cout << -1 << endl;
        }
        else
            cout << min(ans1, ans2) << endl;
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
