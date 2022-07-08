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
    vector<int> v(t);
    vector<int> v1(t - 1);
    fo(i, 0, t) cin >> v[i];
    fo(i, 0, t - 1)
    {
        v1[i] = v[i + 1] - v[i];
    }
    int Max = v1[0];
    fo(i, 1, t - 1)
    {
        if (v1[i] > Max)
            Max = v1[i];
    }
    int Max_defaulti, min_defaulti = INT_MAX;

    fo(i, 0, t - 2)
    {
        Max_defaulti = max(Max, v1[i] + v1[i + 1]);
        min_defaulti = min(min_defaulti, Max_defaulti);
    }
    cout << min_defaulti << endl;
    return 0;
}
