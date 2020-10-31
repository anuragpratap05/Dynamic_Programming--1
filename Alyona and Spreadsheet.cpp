# Dynamic_Programming--1
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    int a[n+1][m+1];
    
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>a[i][j];
        }
    }
    
    int dp[n+1][m+1];
    
    for(int i=1;i<2;i++)
    {
        for(int j=1;j<=m;j++)
        {
            dp[i][j]=1;
        }
    }
    
    for(int i=2;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(a[i][j]>=a[i-1][j])
            {
                dp[i][j]=dp[i-1][j];
            }
            else
            {
                dp[i][j]=i;
            }
        }
    }
    
    /*for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }*/
    
    int q;
    cin>>q;
    for(int i=0;i<q;i++)
    {
        int l,r;
        cin>>l>>r;
        for(int j=1;j<=m;j++)
        {
            if(dp[r][j]<=l)
            {
                cout<<"Yes"<<endl;
                break;
            }
            if(j==m)
            {
                cout<<"No"<<endl;
                break;
            }
        }
        //cout<<endl;
    }
    //int ans[n+1];
    
    
    
    
}
