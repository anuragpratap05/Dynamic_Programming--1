# Dynamic_Programming--1
#include<bits/stdc++.h>
using namespace std;

int health_grid(int** a,int si,int sj,int ei,int ej, int** op)
{
    if(si==ei && sj==ej)
    {
        op[ei][ej]=1;
    }
    
    if(si>ei || sj>ej)
    return INT_MAX;
    
    if(op[si][sj]>-1)
    return op[si][sj];
    
    //int first,second;
    int first = INT_MAX;
     int second = INT_MAX;
    if(si+1<=ei)
     first=health_grid(a,si+1,sj,ei,ej,op)-a[si+1][sj];
    if(sj+1<=ej)
     second=health_grid(a,si,sj+1,ei,ej,op)-a[si][sj+1];
    
    int sa=min(first,second);
    if(sa<=0){
        op[si][sj]=1;
    }
    else
    {
        op[si][sj]=sa;
    }
    
    
    return op[si][sj];
    
    
}


 int main()
 {
     int t;
     cin>>t;
     while(t--){
         int r,c;
         cin>>r>>c;
         int** a=new int*[r];
         for(int i=0;i<r;i++)
         {
             a[i]=new int[c];
         }

         for(int i=0; i<r;i++)
         {
             for(int j=0;j<c;j++)
             {
                 cin>>a[i][j];
             }
         }
         
         int** op=new int*[r];
         for(int i=0;i<r;i++)
         {
             op[i]=new int[c];
         }
         
         for(int i=0; i<r;i++)
         {
             for(int j=0;j<c;j++)
             {
                 op[i][j]=-1;
             }
         }

         int ans=health_grid(a,0,0,r-1,c-1,op);
         cout<<ans<<endl;
         delete [] a;
         delete [] op;
     }
     
 }

