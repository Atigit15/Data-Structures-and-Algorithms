#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define rep(i, a, b) for (int i = a; i < b; i++)
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int LCS(string s1,string s2){
    int n = s1.size();
    int m = s2.size();
    int dp[n+1][m+1];
    rep(i,0,n+1) dp[i][0]=0;
    rep(i,0,m+1) dp[0][i]=0;

    rep(i,1,n+1){
        rep(j,1,m+1){
            if(s1[i-1]==s2[j-1]){
                dp[i][j] = 1+dp[i-1][j-1];
            }
            else{
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    return dp[n][m];
}

int main(){
    fastio
    string s1,s2;
    cin>>s1>>s2;
    int ans=LCS(s1,s2);
    int n=s1.size();
    int m=s2.size();
    cout<<(m+n)-ans<<"\n";
    return 0;
}
