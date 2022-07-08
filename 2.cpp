#include <bits/stdc++.h>
using namespace std;
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
bool isSquare(int n)
{
    if (*(typeid(sqrt(n)).name()) == 'i')
    {
        return true;
    }

    return false;
}
bool isCube(int n)
{
    if (*(typeid(cbrt(n)).name()) == 'i')
    {
        return true;
    }

    return false;
}
int32_t main()
{
    int t = 1;
    cin >> t;
    int count, flag, sum, i, j, temp;
    while (t--)
    {
        count = flag = sum = i = temp = j = 0;
        int a, b;
        cin >> a >> b;
        vector<int> v;
        while (b > 0 && a > 0)
        {
            count = b % 10;
            flag = a % 10;
            b /= 10;
            a /= 10;
            if (count >= flag)
            {
                v.pb(count - flag);
            }
            else
            {
                sum = b % 10;
                if (sum == 1)
                {
                    b /= 10;
                    v.pb(sum * 10 + count - flag);
                }
                else
                {
                    temp = 1;
                    break;
                }
            }
        }
        if (temp == 0 && a == 0)
        {
            if (b > 0)
            {
                cout << b;
                rfo(i, 0, v.size())
                {

                    cout << v[i];
                }
            }
            else
            {
                rfo(i, 0, v.size())
                {
                    if (v[v.size() - 1] == 0 && v.size() > 1)
                    {
                        v[v.size() - 1] = 1;
                    }
                    else
                        cout << v[i];
                }
            }
            cout << endl;
        }
        else
        {
            cout << -1 << endl;
        }
    }

    return 0;
}
