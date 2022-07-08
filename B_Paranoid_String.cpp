#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define int long long
#define vi vector<int>
#define vc vector<char>
#define vvi vector<vector<int>>
#define vvc vector<vector<char>>
#define vvs vector<vector<string>>
#define vs vector<string>
#define seti set<int>
#define setc set<char>
#define sets set<string>
#define vp vector<pair<int, int>>
#define mapi map<int, int>
#define mapc map<char, int>
#define pi (3.141592653589)
#define mod 1000000007
#define float double
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define sz size()
#define len length()
#define inf 1e18
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
    // int n;
    // cin >> n;
    // string s;
    // cin >> s;
    // if (n == 1)
    // {
    //     cout << 1 << endl;
    // }
    // else
    // {
    //     int ans = n;
    //     rfo(i, 1, n)
    //     {
    //         if (s[i] == '1' && s[i - 1] == '0')
    //         {
    //             ans += i;
    //         }
    //         else if (s[i] == '0' && s[i - 1] == '1')
    //         {
    //             ans += i;
    //         }
    //     }
    //     cout << ans << endl;
    // }
    int N;
    cin >> N;

    vector<int> v{1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};
    vector<vector<int>> dp(11, vector<int>(1000001, INT_MAX));
    for (int i = 1; i <= 10; i++)
    {
        dp[i][0] = 0;
    }

    for (int j = 1; j <= N; j++)
    {
        for (int i = 0; i < 10; i++)
        {
            dp[j][v[i]] = 1;
        }
    }

    vector<int> ans;
    vector<int> res;
    for (int i = 1; i <= 10; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if (v[i - 1] <= j)
            {
                dp[i][j] = 1 + dp[i][j - v[i - 1]];
                    ans.push_back(v[i - 1]);
                 if (v[i - 1] == j)
                {
                    cout << "hi" << endl;
                    for (auto x : ans)
                    {
                        cout << x << " ";
                    }
                    cout << endl;
                    ans.clear();
                    if (dp[i - 1][0] > dp[i][0])
                    {

                        res = ans;
                        for (auto x : res)
                        {
                            cout << x << " ";
                        }
                        cout << endl;
                        ans.clear();
                    }
                }
                dp[i][j] = min(dp[i][j], dp[i - 1][j]);
            }
            else
            {
                dp[i][j] = min(dp[i][j], dp[i - 1][j]);
            }
        }
    }
    cout << dp[10][N] << endl;
    for (auto x : res)
    {
        cout << x << " ";
    }
    cout << endl;
}
int32_t main()
{
    fast;
    int t = 1;
    // cin >> t;
    fo(i, 1, t + 1)
    {
        solve();
    }
    return 0;
}
