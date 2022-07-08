#include <bits/stdc++.h>
using namespace std;
#define int long long

#define fo(i, j, n) for (int i = j; i < n; i++)
#define fast ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

int32_t main()
{
    int t = 1;
    cin >> t;
    while (t--)
    {
        string s, ans;
        cin >> s;
        int count = 0;
        if (s[0] == 'E')
        {
            ans = s[0];
            for (auto x : s)

            {
                if (x == 'N')
                {
                    ans += x;
                }
            }
            if (ans == "EN")
            {
                cout << "NO" << endl;
            }
            else
            {
                cout << "YES" << endl;
            }
        }
        else
        {
            for (auto x : s)

            {
                if (x == 'N')
                {
                    ans += x;
                }
                else
                {
                    if (count == 0)
                    {
                        ans += x;
                        count++;
                    }
                }
            }
            if (ans == "NE")
            {
                cout << "NO" << endl;
            }
            else
            {
                cout << "YES" << endl;
            }
        }
    }
    return 0;
}
