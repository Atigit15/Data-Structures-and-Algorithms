#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

//https://cp-algorithms.com/data_structures/sparse-table.html
//Sparse Table - O(1) Query Answer after O(nlogn) Precomputing
//Space - O(nlogn)
//Can be used only on Static Arrays
//Idempotent/Overlap Friendly functions - min,max,gcd,and,or

/*	
				Sparse Table - DP Implementation
				use j=19 for n<=2*1e5
				0-Based
*/
void solve(){
    ll n,q;cin>>n>>q;
    vector<int> v (n);
    for(int i=0;i<n;i++)
    	cin>>v[i];
    vector<vector<int>> dp (n,vector<int> (19,0));
    for(int i=0;i<n;i++)
    	dp[i][0] = v[i];
    for(int j=1;j<19;j++){
    	for(int i=0;i+(1<<j)-1<n;i++){
    		dp[i][j] = min(dp[i][j-1],dp[i+(1<<(j-1))][j-1]);
    	}
    }
    while(q--){
    	int a,b;
    	cin>>a>>b;
    	a--;b--;
    	int k = log2(b-a+1);
    	for(int i=0;i<n;i++){
    		for(int j=0;j<19;j++){
    			cout<<dp[i][j]<<" ";
    		}
    		cout<<"\n";
    	}
    	cout<<min(dp[a][k],dp[b-(1<<k)+1][k])<<"\n";
    }
}

int main(){
    fastio
    ll TC;
    cin>>TC;
    while(TC--) solve();
    return 0;
}