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
        int n, k, x;
        cin >> n >> k;
        vector<int> pos;
        vector<int> neg;
        fo(i, 0, n)
        {
            cin >> x;
            if (x > 0)
            {
                pos.pb(x);
            }
            else
                neg.pb(abs(x));
        }
        sort(all(pos));
        sort(all(neg));
        int cost = 0;
        if (neg.size() == 0)
        {

            for (int i = pos.size() - 1; i >= 0;)
            {

                cost += 2 * pos[i];
                i = i - k;
            }
        }
        else
        {
            for (int i = pos.size() - 1; i >= 0;)
            {

                cost += 2 * pos[i];
                i = i - k;
            }
            for (int i = neg.size() - 1; i >= 0;)
            {

                cost += 2 * neg[i];
                i = i - k;
            }
        }
        if (neg.size() == 0)
        {
            cout << cost - pos[pos.size() - 1] << endl;
        }
        else
            cout << cost - max(pos[pos.size() - 1], abs(neg[neg.size() - 1])) << endl;
    }

    return 0;
}
