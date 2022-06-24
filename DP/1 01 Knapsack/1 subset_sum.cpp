#include<bits/stdc++.h>
using namespace std;
#define pryes cout<<"YES"<<"\n";
#define prno cout<<"NO"<<"\n";
#define rep(i, a, b) for (int i = a; i < b; i++)
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

//tells whether there is a subset of array with given sum

bool isSubsetSum(int set[], int n, int sum)
{
	
	bool dp[n + 1][sum + 1];

	for (int i = 0; i <= n; i++) dp[i][0] = true;

	for (int i = 1; i <= sum; i++) dp[0][i] = false;

	// Fill the subset table in bottom up manner
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= sum; j++) {
			if (set[i - 1] <= j)
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - set[i - 1]];
			else
                dp[i][j] = dp[i - 1][j];
		}
	}
	return dp[n][sum];
}

int main()
{
    int n;cin>>n;
	int set[n];
    rep(i,0,n) cin>>set[i];
    int sum;cin>>sum;
	if (isSubsetSum(set, n, sum)) {pryes;}
	else prno;
	return 0;
}

