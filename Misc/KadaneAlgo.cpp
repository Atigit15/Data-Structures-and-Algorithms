#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pryes cout<<"YES"<<"\n";
#define prno cout<<"NO"<<"\n";
#define REP(i, a, b) for (int i = a; i < b; i++)
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const int mod  = 1e9+7;

void solve(){
    // Kadane's Algorithm
    int n;
    cin>>n;
    ll arr[n];
    REP(i,0,n) cin>>arr[i];
    ll maxofmax = INT_MIN;
    ll sum = INT_MIN; 
    REP(i,0,n){
        sum = max(arr[i],sum+arr[i]);
        maxofmax = max(maxofmax,sum);
    } 
    cout<<maxofmax<<"\n";
}

int main(){
    fastio
    solve();
    return 0;
}
