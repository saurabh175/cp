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
    string s, left, right;
    cin >> s;
    left = s.substr(0, 2);
    right = s.substr(3, 2);
    reverse(all(left));
    if (left > right && left[0] < '6')
    {
        cout << s.substr(0, 3) << left << endl;
    }
    else
    {
        left = s.substr(0, 2);
        int l = stoi(left);
        l = (l + 1) % 24;
        if (l < 10)
        {
            if (l < 6)
                cout << 0 << l << ":" << l << 0 << endl;
            else
            {
                cout << "10:01" << endl;
            }
        }
        else
        {
            if (l >= 20 || l <= 15)
                cout << l << ":" << l % 10 << l / 10 << endl;
            else
            {
                cout << "20:02" << endl;
            }
        }
    }

    return 0;
}
