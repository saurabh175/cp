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
int fun(int i, int n)
{
    return i ^ (n - 1);
}
int32_t main()
{
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> a(n / 2), b(n / 2);
        fo(i, 0, n / 2)
        {
            a[i] = i;
            b[i] = fun(i, n);
        }
        if (k > 0 && k < n - 1)
        {
            int index = min(k, fun(k, n));
            a[index] = k;
            b[index] = n - 1;
            b[0] = fun(k, n);
        }
        if (k == n - 1)
        {
            if (n == 4)
            {
                cout << -1 << endl;
                continue;
            }
            a[0] = n - 2;
            b[0] = n - 1;
            b[1] = n - 3;
            b[2] = 0;
        }
        fo(i, 0, n / 2)
        {
            cout << a[i] << " " << b[i] << endl;
        }
    }
    return 0;
}
