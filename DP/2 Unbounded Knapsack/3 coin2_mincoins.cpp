#include<bits/stdc++.h>
using namespace std;
#define pryes cout<<"YES"<<"\n";
#define prno cout<<"NO"<<"\n";
#define rep(i, a, b) for (int i = a; i < b; i++)
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int min_coins(int arr[], int n,int sum)
{
    sort(arr,arr+n);
	int dp[n + 1][sum + 1] = {0};
	for (int i = 0; i <= n; i++) dp[i][0] = 0;
	for (int i = 0; i <= sum; i++) dp[0][i] = INT_MAX-1;
	for (int i = 1; i <= sum; i++){
        if(i%arr[0]==0) {dp[1][i] = i/arr[0];}
        else dp[1][i] = INT_MAX-1;
    }
 
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= sum; j++) {
			if (arr[i-1] <= j)
                dp[i][j] = min(dp[i - 1][j] ,1 + dp[i][j - arr[i-1]]);
			else
                dp[i][j] = dp[i - 1][j];
		}
	}
	return dp[n][sum];
}

int main()
{
	int arr[3] = {1,3,4};
    int sum;cin>>sum;
	cout<<min_coins(arr,3,sum)<<endl;
	return 0;
}

