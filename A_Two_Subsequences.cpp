#include <bits/stdc++.h>
using namespace std;
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <string>
#include <stdio.h>
#define int long long

int32_t main()
{
    int t = 1;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        char min = s[0];
        for (int i = 1; i < s.length(); i++)
        {
            if (s[i] < min)
            {
                min = s[i];
            }
        }
        cout << min << " ";
        int count=1;
        for (auto x : s)
        {
            if (x != min or count!=1)
            {
                cout << x;
            }
            else count++;
        }
        cout << endl;
    }
    return 0;
}
