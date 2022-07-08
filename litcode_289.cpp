class Solution
{
    int power2(int n)
    {
        int count = 0;
        while (n % 2 == 0 && n > 0)
        {
            count++;
            n /= 2;
        }
        return count;
    }
    int power5(int n)
    {
        int count = 0;
        while (n % 5 == 0 && n > 0)
        {
            count++;
            n /= 5;
        }
        return count;
    }

public:
    int maxTrailingZeros(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> v(n + 2, vector<int>(m + 2));
        for (int i = 1; i < n + 1; i++)
        {
            for (int j = 1; j < m + 1; j++)
            {
                v[i][j] = grid[i - 1][j - 1];
            }
        }

        vector<vector<int>> dp1(n + 2, vector<int>(m + 2));
        vector<vector<int>> dp2(n + 2, vector<int>(m + 2));
        vector<vector<int>> dp3(n + 2, vector<int>(m + 2));
        vector<vector<int>> dp4(n + 2, vector<int>(m + 2));
        vector<vector<int>> dp5(n + 2, vector<int>(m + 2));
        vector<vector<int>> dp6(n + 2, vector<int>(m + 2));
        vector<vector<int>> dp7(n + 2, vector<int>(m + 2));
        vector<vector<int>> dp8(n + 2, vector<int>(m + 2));
        vector<vector<int>> dp9(n + 2, vector<int>(m + 2));
        vector<vector<int>> dp10(n + 2, vector<int>(m + 2));

        for (int i = 1; i < n + 1; i++)
        {
            for (int j = 1; j < m + 1; j++)
            {
                int cost1 = 0, cost2 = 0;
                cost1 = power2(v[i][j]);
                cost2 = power5(v[i][j]);
                dp1[i][j] = cost1;
                dp2[i][j] = cost2;
            }
        }

        for (int i = 1; i < n + 1; i++)
        {
            for (int j = m; j >= 1; j--)
            {
                dp3[i][j] += dp3[i][j + 1] + dp1[i][j];
                dp4[i][j] += dp4[i][j + 1] + dp2[i][j];
            }
        }
        for (int i = 1; i < n + 1; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                dp7[i][j] += dp7[i][j - 1] + dp1[i][j];
                dp8[i][j] += dp8[i][j - 1] + dp2[i][j];
            }
        }
        for (int j = 1; j < m + 1; j++)
        {
            for (int i = n; i >= 1; i--)
            {
                dp9[i][j] += dp9[i + 1][j] + dp1[i][j];
                dp10[i][j] += dp10[i + 1][j] + dp2[i][j];
            }
        }
        for (int i = 1; i < m + 1; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                dp5[j][i] += dp5[j - 1][i] + dp1[j][i];
                dp6[j][i] += dp6[j - 1][i] + dp2[j][i];
            }
        }
        int ans = 0;

        for (int i = 1; i < n + 1; i++)
        {
            for (int j = 1; j < m + 1; j++)
            {
                ans = max(ans, min(dp3[i][j] + dp5[i][j] - dp1[i][j], dp4[i][j] + dp6[i][j] - dp2[i][j]));
                ans = max(ans, min(dp7[i][j] + dp5[i][j] - dp1[i][j], dp8[i][j] + dp6[i][j] - dp2[i][j]));
            }
        }
        for (int i = 1; i < n + 1; i++)
        {
            for (int j = 1; j < m + 1; j++)
            {
                ans = max(ans, min(dp7[i][j] + dp9[i][j] - dp1[i][j], dp8[i][j] + dp10[i][j] - dp2[i][j]));
                ans = max(ans, min(dp3[i][j] + dp9[i][j] - dp1[i][j], dp4[i][j] + dp10[i][j] - dp2[i][j]));
            }
        }
        return ans;
    }
};