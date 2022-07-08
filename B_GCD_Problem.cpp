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
    int min1 = min(a, b);
    int max1 = max(a, b);
    a = max1;
    b = min1;

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
        int n, a, b, c, x, count = 0;

        cin >> n;
        x = n - 1;
        while (x > 0)
        {
            if (n % x == 0)
            {

                c = n / x;
                int i = 2;
                while (i < (x - 1) / 2)
                {

                    if (GCD((x - 1 - i) * c, i * c) == c && i != x - i - 1)
                    {
                        cout << (x - 1 - i) * c << " " << i * c << " " << c << endl;
                        count = 1;
                        break;
                    }
                    else
                        i++;
                }
                if (count != 1)
                {
                    x--;
                }
                else
                {
                    break;
                }
            }
            else
            {
                x--;
            }
        }
        if (count == 0)
        {

            c = 1;
            fo(i, 2, n - 1)
            {
                if (GCD(i, n - i - 1) == 1)
                {
                    cout << i << " " << n - 1 - i << " " << c << endl;
                    break;
                }
            }
        }
    }
    return 0;
}
