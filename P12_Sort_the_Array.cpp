#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fast ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
int32_t main()
{

    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    b = a;
    sort(b.begin(), b.end());
    unordered_map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        m.insert({b[i], i});
    }

    n--;
    int a1 = 1, b1 = 1, x, y;
    int count = 0;
    while (n >= 0)
    {
        if (a[n] == b[n])
        {
            n--;
        }
        else
        {
            if (n < a1)
            {
                cout << "no" << endl;
                return 0;
            }
            else
            {
                y = a[n];
                x = m[y];
                if (a[x] == b[n])
                {
                    count++;

                    if (count == 1)
                    {
                        b1 = n + 1;
                        a1 = x + 1;
                    }
                    a[x] = a[n];
                    n--;
                }
                else
                {
                    cout << "no" << endl;
                    return 0;
                }
            }
        }
    }

    cout << "yes" << endl;
    cout << a1 << " " << b1 << endl;

    return 0;
}
