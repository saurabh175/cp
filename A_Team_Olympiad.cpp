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

    while (t--)
    {
        int n, x;
        cin >> n;
        vector<int> v1, v2, v3;
        fo(i, 0, n)
        {
            cin >> x;
            if (x == 1)
                v1.pb(i + 1);
            else if (x == 2)
                v2.pb(i + 1);
            else
                v3.pb(i + 1);
        }
        int Min = min(v1.size(), min(v2.size(), v3.size()));
        if (Min == 0)
        {
            cout << 0 << endl;
        }
        else
        {
            cout << Min << endl;
            fo(i, 0, Min)
            {
                cout << v1[i] << " " << v2[i] << " " << v3[i] << endl;
            }
        }
    }
    return 0;
}
