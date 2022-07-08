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
string toBinary(int n)
{
    string r;
    while (n != 0)
    {
        r += (n % 2 == 0 ? "0" : "1");
        n /= 2;
    }
    reverse(r.begin(), r.end());
    return r;
}
int32_t main()
{
    int t = 1;
    cin >> t;
    string bit, temp;
    int k = 30;
    const int n = (int)2e5 + 10;
    vector<vector<int>> v(k, vector<int>(n + 1));
    fo(i, 0, k)
    {
        fo(j, 0, n)
        {
            v[i][j + 1] = v[i][j] + ((j & (1 << i)) ? 0 : 1);
        }
    }
    while (t--)
    {
        int l, r, count = 0, mincount = INT_MAX;
        cin >> l >> r;
        fo(i, 0, k)
        {
            mincount = min(mincount, v[i][r + 1] - v[i][l]);
        }
        cout << mincount << endl;
    }
    return 0;
}