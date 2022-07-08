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
        int x, y, temp=0, flag;
        string s;
        cin >> s;
      
        rfo(i, 1, s.size())
        {
            x = s[i] - '0';
            y = s[i - 1] - '0';
            if (x + y >= 10)
            {
                s[i - 1] = (x + y) / 10 + '0';
                s[i] = (x + y) % 10 + '0';
                temp = 1;
                break;
            }
        }
        if (temp == 1)
        {
            cout << s;
            cout << endl;
        }
        else
        {
            x = s[0] - '0';
            y = s[1] - '0';
            s[0] = (x + y) + '0';
            auto it = s.begin();
            it++;
            s.erase(it);
            cout << s << endl;
        }
    }
    return 0;
}
