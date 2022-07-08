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
#define Max3(a, b, c) Max(c, Max(a, b))
#define Max4(a, b, c, d) Max(d, Max(c, Max(a, b)))
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
        int n, Max, nowmax, count = 1;
        cin >> n;
        vector<int> v;
        int x;
        fo(i, 0, n)
        {
            cin >> x;
            v.pb(x);
        }
        Max = v[0];
        fo(i, 1, n)
        {
            if (v[i] > Max)
            {
                Max = v[i];
            }
        }
        nowmax = v[n - 1];
        rfo(i, 0, n)
        {
            if (v[i] == Max)
            {
                if (i == n - 1)
                {
                    count = 0;
                    break;
                }
                else
                {
                    break;
                }
            }
            else if (nowmax < v[i] && v[i] != Max)
            {
                count++;
                nowmax = v[i];
            }
        }
        cout << count << endl;
    }
    return 0;
}
