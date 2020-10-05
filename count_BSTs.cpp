# Dynamic_Programming--1
#include<bits/stdc++.h>
using namespace std;
//int ans=0;

long long int help(int n,int *output)
{
    if(n==0||n==1)
        return 1;
    if(output[n]>0)
        return output[n];
    int ans=0;
     for(int i=1;i<=n;i++)
    {
         ans=(ans+(help(i-1,output)*help(n-i,output)))%1000000007;
        
    }
    output[n]=ans;
    return ans;
}

int countBST( int n)
{
  /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */
    int *output=new int[n+1];
    for(int i=0;i<=n;i++)
    {
        output[i]=0;
    }
   
    return help(n,output)%1000000007;
  
    

}
