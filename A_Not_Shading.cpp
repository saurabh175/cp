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
        int n, m, r, c, count = 0, flag = 0, temp = 0;
        cin >> n >> m >> r >> c;
        vector<vector<char>> v(n, vector<char>(m));
        fo(i, 0, n)
        {
            fo(j, 0, m)
            {
                cin >> v[i][j];
                if (v[i][j] == 'B')
                {
                    count++;
                }
                if (i == r - 1 && j == c - 1)
                {
                    if (v[i][j] == 'B')
                        flag = 1;
                }
            }
        }

        if (flag == 1)
        {
            cout << 0 << endl;
        }
        else if (count == 0)
        {
            cout << -1 << endl;
        }
        else
        {
            fo(i, 0, m)
            {
                if (v[r - 1][i] == 'B')
                {

                    temp = 1;
                    break;
                }
            }
            fo(i, 0, n)
            {
                if (v[i][c - 1] == 'B')
                {
                    temp = 1;
                    break;
                }
            }
            if (temp == 1)
                cout << 1 << endl;
            else
                cout << 2 << endl;
        }
    }
    return 0;
}
