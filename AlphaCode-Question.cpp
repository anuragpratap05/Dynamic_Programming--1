# Dynamic_Programming--1
#include <bits/stdc++.h>

using namespace std;
int m=1000000000+7;
/*int numcodes(int a[], int size)
{
     if(size==0 || size==1)
    {
        return 1;
    }
    
    int sa=numcodes(a,size-1);
    if(a[size-2]*10+a[size-1]<=26)
    sa+=numcodes(a,size-2);
    return sa;
}*/

int numcode2(int a[], int size, int op[])
{
    int sa=0;
    if(size==0 || size==1)
    {
        return 1;
    }
    
    if(op[size]>0)
    return op[size];
    
    if(a[size-1]!=0 )
    sa=(numcode2(a, size-1,op)%m);
    if(a[size-2]*10+a[size-1]<=26 && a[size-2]*10+a[size-1]>=10)
    
    sa+=(numcode2(a,size-2,op)%m);
    op[size]=sa%m;
    
    return sa%m;
}



int main() {
    
     while(1)
    {
    string s;
    cin>>s;
   
	if(s=="0")
        break;
	
    int n=s.length();
    int a[n];
	
	int op[n+1]={0};
    
    for(int i=0;i<n;i++)
    {
        
        a[i] =  (s[i] - 48);
    }
    //int y=numcodes(a,n);
    
    int c=numcode2(a,n,op);
    

    
    //cout<<y<<endl;
    
    cout<<c<<endl;
    }
    

	
	
	
}
