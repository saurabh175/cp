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
int32_t main()
{
    int t = 1, x;
    cin >> t;
    vector<int> v1, v2, v3;
    while (t--)
    {
        cin >> x;
        if (x > 0)
        {
            v2.pb(x);
        }
        else if (x < 0)
            v1.pb(x);
        else
            v3.pb(x);
    }
    if (v1.size() % 2 == 0)
    {
        v3.pb(v1[v1.size() - 1]);
        v1.pop_back();
    }
    if (v2.size() == 0)
    {
        v2.pb(v1[v1.size() - 1]);
        v2.pb(v1[v1.size() - 2]);
        v1.pop_back();
        v1.pop_back();
    }
    cout << v1.size() << " ";
    for (auto x : v1)
        cout << x << " ";
    cout << endl;
    cout << v2.size() << " ";
    for (auto x : v2)
        cout << x << " ";
    cout << endl;
    cout << v3.size() << " ";
    for (auto x : v3)
        cout << x << " ";
    cout << endl;

    return 0;
}
