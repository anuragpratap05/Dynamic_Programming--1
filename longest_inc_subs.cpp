# Dynamic_Programming--1
#include <bits/stdc++.h>
using namespace std;

int lis(int a[],int n)
{
    int* op=new int[n];
    op[0]=1;
    for(int i=1;i<n;i++)
    {
        op[i]=1;
        for(int j=i-1;j>=0;j--)
        {
            if(a[j]>a[i])
            {
                continue;
            }
            int pa=op[j]+1;
            if (pa>op[i])
            op[i]=pa;
        }
    }
    int best=0;
    for(int i=0;i<n;i++)
    {
       if(best<op[i])
       best=op[i];
    }
    
    delete [] op;
    return best;
}

int main()
{
    int n;
    cin>>n;
    int *a=new int[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int ans=lis(a,n);
    cout<<ans;
    delete [] a;
    
}
