# Dynamic_Programming--1
#include<bits/stdc++.h>

int coin_ways(int a[], int n, int v, int** op)
{
    
    //int op[n+1][v+1]={-1};
    
    if(n==0)
    return 0;
    
    if(v==0)
    return 1;
    
    if(v<0)
    return 0;
    
    if(op[n][v]>-1)
    return op[n][v];
    
    int first=coin_ways(a,n,v-a[0],op);
    int second=coin_ways(a+1,n-1,v,op);
    op[n][v]=first+second;
    
    return first+second;
    
    
}


int countWaysToMakeChange(int denominations[], int numDenominations, int value){

  /*  Don't write main().
   *  Don't read input, it is passed as function argument.
   *  Return output and don't print it.
   *  Taking input and printing output is handled automatically.
   */
    
    
    
    
     int** op = new int*[numDenominations+1];
    for(int i = 0; i < numDenominations+1; ++i)
    op[i] = new int[value+1];
    
     for(int i=0;i<=numDenominations;i++)
    {
        for(int j=0;j<=value;j++)
        {
            op[i][j]=-1;
        }
    }
    
    int c=coin_ways(  denominations,  numDenominations, value,op);


}

