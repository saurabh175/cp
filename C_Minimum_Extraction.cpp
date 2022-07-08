#include <bits/stdc++.h>
#include<iostream>
using namespace std;
int32_t main()
{
    int t = 1;
    cin >> t;
    int n;
    while (t--)
    {
        vector<long long> v;
        cin >> n;
        int a;
        for (int i = 0; i < n; i++)
        {
            cin >> a;
            v.push_back(a);
        }
     
        sort(v.begin(), v.end());
       long long min2 =0, max2=v[0];
        for (int i = 0; i < n-1; i++)
        {
            min2+=v[i];
             max2=  max(max2,v[i+1]-min2);
             v[i+1]-=min2;
        }
            cout << max2 << endl;
    }
    return 0;
}
