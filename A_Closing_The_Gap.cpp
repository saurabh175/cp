#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    int t = 1;
    cin >> t;
    int sum = 0, n, x;
    while (t--)
    {
        sum = 0;
        cin >> n;
        x = 0;
        for( int i=0; i<n; i++)
        {
            cin >> x;
            sum += x;
        }
        if (sum % n == 0)
            cout << 0 << endl;
        else
            cout << 1 << endl;
    }
    return 0;
}
