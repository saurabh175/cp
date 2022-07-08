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
    int n, m, flag = 1;
    cin >> n >> m;
    set<pair<int, int>> s;
    vector<vector<char>> v(n, vector<char>(m));
    fo(i, 0, n)
    {
        fo(j, 0, m)
        {
            cin >> v[i][j];
            if (v[i][j] == '-')
                s.insert({i, j});
        }
    }
    fo(i, 0, n)
    {
        fo(j, 0, m)
        {
            if (j == 0)
            {
                if (j == 0 && i == 0)
                    v[i][j] = 'B';
                else
                {
                    if (v[i - 1][j] == 'B')
                        v[i][j] = 'W';
                    else
                        v[i][j] = 'B';
                }
            }
            else if (v[i][j - 1] == 'W')
                v[i][j] = 'B';
            else
                v[i][j] = 'W';
        }
    }
    fo(i, 0, n)
    {
        fo(j, 0, m)
        {
            if (s.find({i, j}) != s.end())
            {
                cout << "-";
            }
            else
                cout << v[i][j];
        }
        cout << endl;
    }
    return 0;
}
