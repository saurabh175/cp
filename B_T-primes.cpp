#include <bits/stdc++.h>
using namespace std;
bool isPrime(int n)
{
    if (n == 1)
        return false;
    if (n == 2)
        return true;
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

int32_t main()
{
    int t = 1;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        long long s = sqrt(n);
        long long k = s * s;
        if (k == n)
        {
            if (isPrime(s))
            {
                cout << "YES" << endl;
            }
            else
            {
                cout << "NO" << endl;
            }
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}
