# Dynamic_Programming--1
#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;
int go(vector<int> v){
	int n = v.size();
	vector<vector<int>> dp(101, vector<int>(n, 0));

	for (int i = 0; i < n; ++i)
		{
			dp[v[i]][i] = 1;
		}	

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < i; ++j)
		{
			if (v[i]>v[j])
			{
				for (int k = 1; k < 101; ++k)
				{
					int gcn = __gcd(k, v[i]);
					dp[gcn][i] = (dp[gcn][i]+dp[k][j])%mod;
				}
			}
		}
	}

	int ans = 0;
	for (int i = 0; i < n; ++i)
	{
		ans=(ans+ dp[1][i])%mod;
	}

	return ans%mod;


}

int main()
{
	

	int n;
	cin>>n;
	vector<int> v(n, 0);

	for (int i = 0; i < n; ++i)
	{
		cin>>v[i];	
	}

	cout << go(v) << '\n';



	return 0 ; 


}

