# Dynamic_Programming--1
#include <iostream>
using namespace std;

int min_cost2(int** input, int m, int n) {
	int ** dp = new int*[m];
	for (int i = 0; i < m; i++) {
		dp[i] = new int[n];
	}
	dp[m - 1][n-1] = input[m-1][n-1];
	for (int i = m - 2; i >= 0; i--) {
		dp[i][n -1] = dp[i + 1][n-1] + input[i][n-1];
	}

	for (int j = n - 2; j >=0; j--) {
		dp[m -1][j] = dp[m - 1][j + 1] + input[m-1][j];
	}

	for (int i = m - 2; i >=0; i--) {
		for (int j = n - 2; j >=0 ; j--) {
			dp[i][j] = input[i][j] + min(dp[i+1][j], min(dp[i+1][j+1], dp[i][j + 1]));
		}
	}
	return dp[0][0];
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
            cin>>a[i][j];
        }
    }


cout << min_cost2(a,3,3) << endl;

    /*for(int i=0;i<n;i++)
    {
        for(int j=0;j<m; j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }*/

}
