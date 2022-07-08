#include <bits/stdc++.h>
using namespace std;
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <string>
#include <stdio.h>
#define int long long
#define pi (3.141592653589)
#define mod 1000000007
#define int long long
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
#define rrep(i, n) for(int i=n-1;i>=0;i--)
#define rep(i,n) for(int i=0;i<n;i++)
#define fast ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);


bool isPrime(int n){
if(n==1) return false;
if(n==2) return true;
for(int i=2;i*i<=n;i++){
if(n%i==0)return false;
}
return true;
}

int32_t main()
{
    int t = 1;
    cin >> t;
    while (t--)
    {
        double s, a, b, c;
        double k;
        cin >> s >> a >> b >> c;
        if (c>0)
        {
             k=s+(s*c)/100;
          
        }
        else k=s-(s*c)/100;
       
        if(k>=a&&k<=b){
            cout<<"YES"<<endl;
        }
        else cout<<"NO"<<endl;
    }
    return 0;
}
