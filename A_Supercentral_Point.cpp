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
    int n = 1, x, y;
    cin >> n;
    vector<pair<int, int>> v(n);
    fo(i, 0, n)
    {
        cin >> v[i].first >> v[i].second;
    }
    int flag = 0, l, r, u, d;
    fo(i, 0, n)
    {
        l = r = u = d = 0;
        fo(j, 0, n) //left,right
        {
            if (v[j].second == v[i].second)
            {
                if (v[j].first < v[i].first)
                    l = 1;
                else if(v[j].first > v[i].first)
                    r = 1;
            }
        }

        fo(j, 0, n) //up,down
        {
            if (v[j].first == v[i].first)
            {
                if (v[j].second < v[i].second)
                    u = 1;
                else if (v[j].second > v[i].second)
                    d = 1;
            }
        }

        if (l == 1 && r == 1 && u == 1 && d == 1)
            flag++;
    }
    cout << flag << endl;
    return 0;
}
