#include<bits/stdc++.h>
using namespace std;
#define pryes cout<<"YES"<<"\n";
#define prno cout<<"NO"<<"\n";
#define rep(i, a, b) for (int i = a; i < b; i++)
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int maxProfit(int arr[], int n)
{
	
	int dp[n + 1][n + 1];
	for (int i = 0; i <= n; i++) dp[i][0] = 0;
	for (int i = 1; i <= n; i++) dp[0][i] = 0;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i <= j)
                dp[i][j] = max(dp[i - 1][j] , arr[i-1] + dp[i][j - i]);
			else
                dp[i][j] = dp[i - 1][j];
		}
	}
	return dp[n][n];
}

int main()
{
    int n;cin>>n;
	int arr[n];
    rep(i,0,n) cin>>arr[i];
	cout<<maxProfit(arr,n)<<endl;
	return 0;
}

