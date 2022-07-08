#include <bits/stdc++.h>
using namespace std;
map<string, int> dp;
int solve(string s)
{
  //  cout << s << " " << dp[s] << endl;
    if (dp[s] == 1)
        return 1;
    if (dp[s] == 2)
        return 0;
    if (s.size() == 1)
        return 0;
    int n = s.size();
    // cout << s << endl;
    int ans = 0;
    dp[s] = 0;
    for (int i = 0; i < n; i++)
    {
        ans=0;
        if (i == n - 1)
        {
            // cout << s.substr(0, i + 1) << " last" << endl;
            if (dp[s.substr(0, i + 1)] == 1)
                ans = 1;
            else
            {
                ans = 0;
                dp[s.substr(0, i + 1)] = 2;
            }
        }
        else
        {
            // cout << s.substr(0, i + 1) << " " << s.substr(i + 1, n - i - 1) << endl;
            int left = solve(s.substr(0, i + 1));
            if (left == 1)
                dp[s.substr(0, i + 1)] = 1;
            else
                dp[s.substr(0, i + 1)] = 2;
            // cout << s.substr(0, i + 1) << " " << left << endl;
            int right = 0;
            if (left == 1)
            {
                right = solve(s.substr(i + 1, n - i - 1));
                if (right == 1)
                {
                    dp[s.substr(i + 1, n - i - 1)] = 1;
                }
                else
                {
                    dp[s.substr(i + 1, n - i - 1)] = 2;
                }
            }
            else
            {
                dp[s.substr(i + 1, n - i - 1)] = 2;
            }
            ans = (ans || (left && right));
           // cout << ans << endl;
        }
        if (ans == 1)
            dp[s] = (dp[s] || ans);
        else dp[s]=2;
    }
    if (dp[s]==1)
        return 1;
    else
        return 0;
}

int solve1()
{
    int n;
    cin >> n;
    vector<string> B(n);
    for (int i = 0; i < n; i++)
    {
        cin >> B[i];
    }
    string A;
    cin >> A;
    for (int i = 0; i < B.size(); i++)
    {
        dp[B[i]] = 1;
    }
    return solve(A);
}

int32_t main()
{
    cout << solve1();
    return 0;
}
