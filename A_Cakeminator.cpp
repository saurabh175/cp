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
        int r, c, maxcount = 0, count = 0;
        cin >> r >> c;
        vector<vector<char>> v(r, vector<char>(c));
        fo(i, 0, r)
        {
            fo(j, 0, c)
            {
                cin >> v[i][j];
            }
        }
        fo(i, 0, r)
        {
            count = 0;
            fo(j, 0, c)
            {
                if (v[i][j] != 'S')
                {
                    if (v[i][j] != '0')
                    {
                        count++;
                    }
                }
                else
                {
                    count = 0;
                    break;
                }
            }
            if (count != 0)
            {
                fo(j, 0, c)
                {
                    v[i][j] = '0';
                }
            }
            maxcount += count;
        }
        fo(i, 0, c)
        {
            count = 0;
            fo(j, 0, r)
            {
                if (v[j][i] != 'S')
                {
                    if (v[j][i] != '0')
                    {
                        count++;
                                        }
                }
                else
                {
                    count = 0;
                    break;
                }
            }
            if (count != 0)
            {
                fo(j, 0, r)
                {
                    v[j][i] = '0';
                }
            }
            maxcount += count;
        }
        cout << maxcount << endl;
    }
    return 0;
}
