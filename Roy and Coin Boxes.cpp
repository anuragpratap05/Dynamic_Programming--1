# Dynamic_Programming--1
#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long n,m;
    cin>>n>>m;
    long long s[n+1]={0};
    long long e[n+1]={0};
    for(long long i=0;i<m;i++)
    {
        long long l,r;
        cin>>l>>r;
        s[l]+=1;
        e[r]+=1;
    }
    
    long long dp[n+1]={0};
    
    dp[1]=s[1];
    for(long long i=2;i<=n;i++)
    {
        dp[i]=dp[i-1]+s[i]-e[i-1];
    }
    /*for(int i=0;i<=n;i++)
    {
        cout<<dp[i]<<" ";
    }
    cout<<endl;*/
    long long freq[n+1]={0};
    
    for(long long i=1;i<=n;i++)
    {
        freq[dp[i]]++;
    }
    
    /*for(int i=0;i<=n;i++)
    {
        cout<<freq[i]<<" ";
    }*/
    //cout<<endl;
    long long ans[n+1]={0};
    ans[n]=freq[n];
    for(long long i=n-1;i>=1;i--)
    {
        ans[i]=freq[i]+ans[i+1];
    }
   // cout<<endl;
   /* for(int i=0;i<=n;i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;*/
    long long q;
    cin>>q;
    for(long long i=0;i<q;i++)
    {
        long long x;
        cin>>x;
        cout<<ans[x]<<endl;
    }
}
