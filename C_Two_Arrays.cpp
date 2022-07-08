#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main()
{
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int>a(n);
        vector<int>b(n);
        int count = 0;
       
        // unordered_multiset<int> m;
        // typedef unordered_multiset<int>::iterator umit;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        sort(a.begin(),a.end());
        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
          //  m.insert(b[i]);
        }
       sort(b.begin(),b.end());
       bool t=true;
       for (int i = 0; i < n; i++)
       {
          t&=(b[i]-a[i]==0||b[i]-a[i]==1) ;
       }
       if(t==true){
           cout<<"YES"<<endl;
       }
       else{
           cout<<"NO"<<endl;
       }
        // for (int i = 0; i < n; i++)
        // {
        //     if (m.find(a[i]) != m.end())
        //     {
        //         count++;
        //         umit it = m.find(a[i]);
        //         m.erase(it);
               
        //     }
        //     else if (m.find(a[i] + 1) != m.end())
        //     {
        //         count++;
        //         umit it = m.find(a[i] + 1);
        //         m.erase(it);
               
        //     }
        //     else{
        //         break;
        //     }
        // }
        // if (count == n)
        // {
        //     cout << "YES" << endl;
        // }
        // else
        //     cout << "NO" << endl;
    }
    return 0;
}
