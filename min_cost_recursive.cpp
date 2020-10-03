# Dynamic_Programming--1
#include<bits/stdc++.h>
using namespace std;


int min_cost(int** a, int si, int sj, int ei, int ej,int** op)
{
    if(si==ei && sj==ej)
    {
        op[ei][ej] = a[ei][ej];
        return op[ei][ej];
    }

    if(si>ei || sj>ej )
        return INT_MAX;


    int option1=min_cost(a,si+1,sj,ei,ej,op);
    int option2=min_cost(a,si,sj+1,ei,ej,op);
    int option3=min_cost(a,si+1,sj+1,ei,ej,op);
    op[si][sj] =  a[si][sj]+min(option1,min(option2,option3));
    return op[si][sj];

}


int main()
{
    int n,m;
    n=3;
    m=3;

    int** a=new int*[n];
    for(int i=0;i<n;i++)
    {
        a[i]=new int[m];
    }

    int** op=new int*[n];
    for(int i=0;i<n;i++)
    {
        op[i]=new int[m];
    }

     for(int i=0;i<n;i++)
    {
        for(int j=0;j<m; j++)
        {
            op[i][j]=-1;
        }
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m; j++)
        {
            cin>>a[i][j];
        }
    }



    int c=min_cost(a,0,0,2,2,op);
    cout<<c<<endl;

    /*for(int i=0;i<n;i++)
    {
        for(int j=0;j<m; j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }*/

}
