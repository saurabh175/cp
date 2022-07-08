#include <bits/stdc++.h>
using namespace std;

int32_t main()
{
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> v(n + 1, vector<char>(m + 1, '0'));
        int count;
        int maxcount = 1;
        int maxi = 1, maxj = 1;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                cin >> v[i][j];
            }
        }

        for (int i = 1; i <= n; i++)
        {

            for (int j = 1; j <= m; j++)
            {
                count = 0;
                int tempx = i, tempy = j;

                set<pair<int, int>> set_var;
                stack<pair<int, int>> st;
                    set_var.insert({tempx, tempy});
                    st.push({tempx, tempy});
                
                while (1)
                {

                    char c = v[tempx][tempy];
                    if (c == 'L')
                    {
                        tempy--;
                    }
                    if (c == 'R')
                    {
                        tempy++;
                    }
                    if (c == 'U')
                    {
                        tempx--;
                    }
                    if (c == 'D')
                    {
                        tempx++;
                    }
                    if (tempx > 0 && tempx <= n && tempy > 0 && tempy <= m)
                    {

                        if (set_var.find({tempx, tempy}) == set_var.end())
                        {

                            set_var.insert({tempx, tempy});
                            st.push({tempx, tempy});
                        }
                        else
                        {
                            

                            while (!st.empty())
                            {
                                st.pop();
                                count++;
                               
                            }
                            if (count > maxcount)
                            {
                                maxi = i, maxj = j;
                                maxcount = count;
                            }
                            break;
                        }
                    }
                    else
                    {

                        while (!st.empty())
                        {
                            st.pop();
                            count++;
                        }
                        if (count > maxcount)
                        {
                            maxi = i, maxj = j;
                            maxcount = count;
                        }
                        break;
                    }
                }
            }
        }

        cout << maxi << " " << maxj << " " << maxcount << endl;
    }
    return 0;
}
