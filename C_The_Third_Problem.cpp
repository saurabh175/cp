#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long LL;

int N,K;
LL L[1005],R[1005];
double dp[1005][105],p[1005];

LL Ans(LL n)
{
    LL ans=0;
    LL t=1;
    for (int i=1;i<=n;i++)
    {
        ans+=t;
        t*=10;
    }
    return ans;
}

LL solve(LL n)
{
    if (n<=0) return 0;
    if (n<=9) return 1;
    vector<int> dig;
    while (n)
    {
        dig.push_back(n%10);
        n/=10;
    }
    reverse(dig.begin(),dig.end());
    if (dig[0]==1)
    {
        LL res=0;
        for (int i=1;i<dig.size();i++)
        {
            res*=10;
            res+=dig[i];
        }
        return res+1+Ans(dig.size()-1);
    }
    else return Ans(dig.size());
}

double Pro(int i)
{
    return (solve(R[i])-solve(L[i]-1))/(double)(R[i]-L[i]+1);
}

int main()
{
    //freopen("input.txt","r",stdin);
    cin>>N;
    for (int i=1;i<=N;i++)
    {
        cin>>L[i]>>R[i];
        p[i]=Pro(i);
        //cout<<p[i]<<endl;
    }
    cin>>K;
    dp[1][1]=p[1];
    dp[1][0]=1-p[1];
    for (int i=2;i<=N;i++)
    {
        double p1=p[i],p2=1-p1;
        dp[i][0]+=p2*dp[i-1][0];
        if (dp[i][0]<=1e-100) dp[i][0]=0;
        for (int k=1;k<=i;k++)
        {
            dp[i][k]+=dp[i-1][k-1]*p1;
            dp[i][k]+=dp[i-1][k]*p2;
            if (dp[i][k]<=1e-100) dp[i][k]=0;
        }
    }
    double ans=0.0;
    for (int i=0;i<=N;i++) if (i*100>=K*N) ans+=dp[N][i];
    printf("%.18lf",ans);
    return 0;
}