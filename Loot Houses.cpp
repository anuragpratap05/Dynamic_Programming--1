# Dynamic_Programming--1
#include<bits/stdc++.h>

int max_loot(int a[], int n,int i, int op[])
{
    if(i>n)
    {
        op[i]=0;
        return 0;
    }
    
    if(op[i]>-1)
    return op[i];
    
    int f=INT_MIN;
    int s=INT_MIN;
    
    f=a[i]+max_loot(a,n,i+2,op);
    s=max_loot(a,n,i+1,op);
    int sa=max(f,s);
    op[i]=sa;
    return sa;
}

int maxMoneyLooted(int *arr, int n)
{
	//Write your code here
    
     int op[n+3];
    for(int i=0;i<n+3;i++)
    {
        op[i]=-1;
    }
    
    max_loot(arr,n-1,0,op);
}
