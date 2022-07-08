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
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n, a, b;
        cin >> n >> a >> b;
        int l = max(a, b);
        int s = min(a, b);
        vector<int> v;
        if (a == 0 && b == 0)
        {
            fo(i, 1, n + 1)
            {
                cout << i << " ";
            }
            cout << endl;
        }

        else if (a == b)
        {
            if (n < 2 * a + 2)
            {
                cout << -1 << endl;
            }
            else
            {
                cout << 1 << " ";
                fo(i, 2, 2 * a + 3)
                {
                    if (i % 2 == 0)
                    {
                        if (i == 2 * a + 2)
                        {
                            v.pb(i);
                        }
                        else
                            v.pb(i + 1);
                    }
                    else
                    {
                        v.pb(i - 1);
                    }
                }
                for (auto x : v)
                {
                    cout << x << " ";
                }
                int x = 2 * a + 2;
                while (x++ < n)
                {
                    cout << x << " ";
                }
                cout << endl;
            }
        }
        else if (l * 2 + 1 > n)
        {
            cout << -1 << endl;
        }
        else if (l - s == 1)
        {
            if (a > b)
            {
                int x = n - (2 * (b + 1) + 1);
                fo(i, 2, 2 * (b + 1) + 2)
                {
                    if (i % 2 == 0)
                    {
                        v.pb(i + 1);
                    }
                    else
                    {
                        v.pb(i - 1);
                    }
                }
                int i = 1;
                fo(i, 0, v.size())
                {
                    v[i] += x;
                }
                while (i < v[1])
                {
                    cout << i++ << " ";
                }
                for (auto y : v)
                {
                    cout << y << " ";
                }

                cout << endl;
            }
            else
            {
                cout << 2 << " ";
                fo(i, 2, 2 * (a + 1) + 2)
                {
                    if (i % 2 == 0)
                    {
                        v.pb(i - 1);
                    }
                    else
                    {
                        if (i == 2 * (a + 1) + 1)
                        {
                            v.pb(i);
                        }
                        else
                            v.pb(i + 1);
                    }
                }
                for (auto x : v)
                {
                    cout << x << " ";
                }
                int x = 2 * (a + 1) + 1;
                while (x++ < n)
                {
                    cout << x << " ";
                }
                cout << endl;
            }
        }
        else
        {
            cout << -1 << endl;
        }
    }
    return 0;
}
