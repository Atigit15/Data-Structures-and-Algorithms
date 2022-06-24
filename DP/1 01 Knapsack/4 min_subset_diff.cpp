#include<bits/stdc++.h>
using namespace std;
#define pryes cout<<"YES"<<"\n";
#define prno cout<<"NO"<<"\n";
#define rep(i, a, b) for (int i = a; i < b; i++)
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const int MOD = 1e9 + 7;

//divide array in two subset such that their diff is min
//o/p - min diff.

bool dp[102][1002];

bool isSubsetSum(int set[], int n, int sum)
{
	for (int i = 0; i <= n; i++) dp[i][0] = true;
	for (int i = 1; i <= sum; i++) dp[0][i] = false;

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

int MinSubsetDiff(int arr[], int n)
{
    int sum=0;
    rep(i,0,n) sum+=arr[i];
    int s;s=sum/2;
    bool p = isSubsetSum(arr,n,s);
    for(int j=s;j>=0;j--) if(dp[n][j]==1) {s=j;break;}
	return sum-2*s;
}

int main()
{
    int n;cin>>n;
	int arr[n];
    rep(i,0,n) cin>>arr[i];
	cout<<MinSubsetDiff(arr, n)<<endl;
	return 0;
}

