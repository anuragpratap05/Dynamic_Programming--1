# Dynamic_Programming--1
// C++ program to count number of binary strings 
// with k times appearing consecutive 1's. 
#include <bits/stdc++.h> 
using namespace std; 
//#typedef 1000000007 mod;
int countStrings(int n, int k) 
{ 
	// dp[i][j][0] stores count of binary 
	// strings of length i with j consecutive 
	// 1's and ending at 0. 
	// dp[i][j][1] stores count of binary 
	// strings of length i with j consecutive 
	// 1's and ending at 1. 
	int dp[n + 1][k + 1][2]; 
	memset(dp, 0, sizeof(dp)); 

	// If n = 1 and k = 0. 
	dp[1][0][0] = 1; 
	dp[1][0][1] = 1; 

	for (int i = 2; i <= n; i++) { 

		// number of adjacent 1's can not exceed i-1 
		for (int j = 0; j <= k; j++) { 
			dp[i][j][0] = (dp[i - 1][j][0]%1000000007 + dp[i - 1][j][1]%1000000007)%1000000007; 
			dp[i][j][1] = dp[i - 1][j][0]; 

			if (j - 1 >= 0) 
				dp[i][j][1] += dp[i - 1][j - 1][1]%1000000007; 
		} 
	} 
	
	/*for(int i=0;i<=n;i++)
	{
	    for(int j=0;j<=k;j++)
	    {
	        for(int k=0;k<=1;k++)
	        {
	            cout<<dp[i][j][k]<<" ";
	        }
	        cout<<endl;
	    }
	    cout<<endl;
	}
	cout<<endl;*/

	return (dp[n][k][0]%1000000007 + dp[n][k][1]%1000000007)%1000000007; 
} 

// Driver code 
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        
    
    int x,n,k;
    cin>>x>>n>>k;
    
	//int n = 20, k = 8; 
	cout << x<<" "<<countStrings(n, k)<<endl;
    }
	return 0; 
}


