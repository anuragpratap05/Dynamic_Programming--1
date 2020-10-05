# Dynamic_Programming--1
#include<bits/stdc++.h>
using namespace std;

int main()
{
    string n;
    cin>>n;
    
    int ts=n[0]-'0';
    int last=n[0]-'0';
    
    for(int i=1;i<n.length();i++)
    {
        last=last*10+(n[i]-'0')*(i+1);
        ts=ts+last;
    }
    cout<<ts<<endl;
}
