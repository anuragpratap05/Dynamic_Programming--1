# Dynamic_Programming--1
#include<bits/stdc++.h>
using namespace std;



int main()
{
    int n,k,x;
    cin>>n>>k>>x;
    int freq[1024]={0};
    int ans[1024]={0};
    for(int i=0;i<n;i++)
    {
        int val;
        cin>>val;
        
        freq[val]++;
        
    }
    
    
    /*for(int i=0;i<50;i++)
    {
        cout<<freq[i]<<" ";
    }
    cout<<endl;*/
    
    
    
    while(k--)
    {
        int sum=0;
    for(int i=0;i<=1024;i++)
    {
        
        
        if(freq[i]!=0)
        {
            
        int xxor=i^x;
        if(freq[i]%2==0)
        {
            int mid=freq[i]/2;
            ans[i]+=mid;
            ans[xxor]+=mid;
        }
        
        else
        {
            int mid1=freq[i]/2;
            if(sum%2==0)
            {
                ans[xxor]+=mid1+1;
                ans[i]+=mid1;
            }
            else
            {
                ans[xxor]+=mid1;
                ans[i]=ans[i]+(mid1+1);
            }
            /*for(int i=0;i<35;i++)
            {
                cout<<ans[i]<<" ";
            }
            cout<<endl;*/
        }
        sum+=freq[i];
        
        }
    }
    for (int i = 0; i < 1024; i++)
    {
      freq[i] = ans[i];
        ans[i]=0;
    }
    }
    cout<<endl;
    
    for(int i=1023;i>=0;i--)
    {
        if(freq[i]!=0)
        {
            cout<<i<<" ";
            break;
        }
    }
    
    for(int i=0;i<1024;i++)
    {
        if(freq[i]!=0)
        {
            cout<<i;
            break;
            
        }
    }
    
    
    /*cout<<endl;
    for(int i=0;i<20;i++)
    {
        cout<<ans[i]<<" ";
    }*/
}
