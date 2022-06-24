#include<bits/stdc++.h>
using namespace std;
#define pryes cout<<"YES"<<"\n";
#define prno cout<<"NO"<<"\n";
#define rep(i, a, b) for (int i = a; i < b; i++)
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int total_ways(int arr[], int n,int sum)
{
	
	int dp[n + 1][sum + 1];
	for (int i = 0; i <= n; i++) dp[i][0] = 1;
	for (int i = 1; i <= sum; i++) dp[0][i] = 0;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= sum; j++) {
			if (arr[i-1] <= j)
                dp[i][j] = dp[i - 1][j] + dp[i][j - arr[i-1]];
			else
                dp[i][j] = dp[i - 1][j];
		}
	}
	return dp[n][sum];
}

int main()
{
    int n;cin>>n;
	int arr[n];
    rep(i,0,n) cin>>arr[i];
    int sum;cin>>sum;
	cout<<total_ways(arr,n,sum)<<endl;
	return 0;
}

