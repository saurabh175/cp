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
    string s1, s2, s3, s4;
    cin >> s1 >> s2 >> s3 >> s4;
  
    vector<pair<int, char>> v;
    v.pb({s1.length() - 2, 'A'});
    v.pb({s2.length() - 2, 'B'});
    v.pb({s3.length() - 2, 'C'});
    v.pb({s4.length() - 2, 'D'});
    sort(all(v));
    if (2 * v[0].first <= v[1].first)
    {
         if (v[3].first >= 2 * v[2].first)
            cout << "C" << endl;
         
        else cout << v[0].second << endl;
    }
    else if (v[3].first >= 2 * v[2].first)
    {
        if (2 * v[0].first <= v[1].first)
            cout << "C" << endl;
        else
            cout << v[3].second << endl;
    }
    else
        cout << "C" << endl;
    return 0;
}
