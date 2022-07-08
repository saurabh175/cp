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
    int r1, r2, c1, c2, d1, d2, a, b, c, d;
    cin >> r1 >> r2 >> c1 >> c2 >> d1 >> d2;
    fo(i, 1, 10)
    {
        a = i;
        b = r1 - a;
        if (b < 10 && b > 0)
        {
            c = c1 - a;
            d = c2 - b;

            if (c > 0 && d > 0 && c < 10 && d < 10)
            {
                if (a + d == d1 && b + c == d2 && c + d == r2 && a != b && c != d && a != c && a != d && b != c && b != d && c != d)
                {
                    cout << a << " " << b << endl;
                    cout << c << " " << d << endl;
                    return 0;
                }
            }
        }
    }
    cout << -1 << endl;

    return 0;
}
