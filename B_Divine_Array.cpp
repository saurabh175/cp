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
#define rfo(i,j, n) for(int i=n-1;i>=j;i--)
#define fo(i,j,n) for(int i=j;i<n;i++)
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

int32_t main()
{
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<vector<int>> a(n+1, vector<int>(n, 0));
        unordered_map<int, int> mp;
        fo(i,0, n)
        {
            cin >> a[0][i];
            mp[a[0][i]]++;
        }
        fo(i,1, n+1)
        {
            fo(j,0, n)
            {
                a[i][j] = mp[a[i-1][j]];
            }
             fo(j,0, n)
            {
                mp[a[i][j]]=0;
            }
            fo(j,0, n)
            {
                mp[a[i][j]]++;
            }
        }
        int q;
        cin >> q;
        while (q--)
        {
            int x, k;
            cin >> x >> k;
            if (k >= n)
            {
                cout << a[n][x - 1] << endl;
            }
            else
                cout << a[k][x - 1] << endl;
        }
    }
    return 0;
}
