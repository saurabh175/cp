#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vector<int>>
#define vs vector<string>
#define set set<int>
#define sets set<string>
#define vp vector<pair<int, int>>
#define map map<int, int>
#define umap unordered_map<int>
#define pi (3.141592653589)
#define mod 1000000007
#define float double
#define vb vector<bool>
#define vvb vector<vb>
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define sz size()
#define len length()
#define all(c) c.begin(), c.end()
#define min3(a, b, c) min(c, min(a, b))
#define min4(a, b, c, d) min(d, min(c, min(a, b)))
#define max3(a, b, c) max(c, max(a, b))
#define max4(a, b, c, d) max(d, max(c, max(a, b)))
#define rfo(i, j, n) for (int i = n - 1; i >= j; i--)
#define fo(i, j, n) for (int i = j; i < n; i++)
#define fast ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

void solve()
{
    // string s;
    // cin >> s;
    // int n = s.length();
    // vvi dp(n + 1, vi(n + 1));
    // vector<vector<bool>> is(n + 1, vector<bool>(n + 1, true));
    // // is_spalindrom for range l r;
    // rfo(i, 1, n + 1)
    // {
    //     fo(j, i, n + 1)
    //     {

    //         if (i == j)
    //         {
    //             is[i][j] = 1;
    //             continue;
    //         }
    //         if (s[i - 1] != s[j - 1])
    //         {
    //             is[i][j] = 0;
    //         }
    //         else
    //         {
    //             is[i][j] = is[i + 1][j - 1];
    //         }
    //     }
    // }
    // rfo(i, 1, n + 1)
    // {
    //     fo(j, i, n + 1)
    //     {
    //         if (i == j)
    //         {
    //             dp[i][j] = 1;
    //             continue;
    //         }
    //         dp[i][j] = is[i][j];
    //         dp[i][j] += dp[i + 1][j] + dp[i][j - 1] - dp[i + 1][j - 1];
    //     }
    // }
    // int q;
    // cin >> q;
    // int l, r;
    // fo(i, 0, q)
    // {
    //     cin >> l >> r;
    //     cout << dp[l][r] << endl;
    // }

    string s; // 0 based indexing
    cin >> s;
    int n = (int)s.size();

    vvb is(n + 2, vb(n + 2, true)); // use a 2D boolean vector
    vvi ans(n + 2, vi(n + 2, 0));   // use a 2D integer vector

    for (int i = n; i >= 1; i--)
    { // loop i from N to 1
        for (int j = 1; j <= n; j++)
        { // loop j from 1 to N
            if (j < i)
                continue;
            if (i == j)
            {
                is[i][j] = 1;
                continue;
            }

            if (s[i - 1] != s[j - 1])
                is[i][j] = 0; // the first and last elements in the substring of a palindrome should be equal
            // do s[i - 1] and s[j - 1] for converting 1-based indexing to 0-based indexing
            else
                is[i][j] = is[i + 1][j - 1]; // is[i + 1][j - 1] it could be that
            // i + 1 > j - 1 => we would get the incorrect value of false when actually is[i][j] is true
            // another way is to check if i + 1 > j - 1 and then set is[i][j] to be true
        }
    }

    // precomputation of is_palindrome[i][j] is done for all i<=j

    for (int i = n; i >= 1; i--)
    {
        for (int j = 1; j <= n; j++)
        {
            if (j < i)
                continue;
            if (i == j)
            {
                ans[i][j] = 1;
                continue;
            }                     // because {s[i]} would be the only palindromic substring
            ans[i][j] = is[i][j]; // 1 or 0 depending on whether or not i...j is a palindrome
            ans[i][j] += ans[i + 1][j] + ans[i][j - 1] - ans[i + 1][j - 1];
        }
    }

    // precomputation of ans[i][j] is done for all i<=j

    int q;
    cin >> q;
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        cout << ans[l][r] << '\n';
    }
}
int32_t main()
{

    fast;
    solve();
    return 0;
}
