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
        int n, a, b, c, d, e, g;
        cin >> n;
        vector<int> v(n), v1, v2, v3, v4;
        fo(i, 0, n) cin >> v[i];

        fo(i, 0, n)
        {
            a = v[i], b = a;
            fo(j, i + 1, n)
            {
                if (v[j] < a)
                {
                    a = v[j];
                }
                else if (v[j] > b)
                {
                    b = v[j];
                }
            }
           
            vector<int> f(b + 2, 0);
            c = i, d = 0, e = b + 1;
            while (d != e && c < n)
            {

                if (f[v[c]] == 0)
                {
                    g = c;
                    d++;
                    f[v[c]] = 1;
                }
                c++;
            }

            fo(j, 0, b + 2)
            {

                if (f[j] == 0)
                {
                    v3.pb(j);

                    break;
                }
            }
            i = g;
        }
        cout << v3.size() << endl;
        for (auto x : v3)
        {
            cout << x << " ";
        }
        cout << endl;
    }
    return 0;
}
