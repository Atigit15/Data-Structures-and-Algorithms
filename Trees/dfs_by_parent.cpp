#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long int
#define vi vector<ll>
#define vvi vector<vi>
#define all(x) (x).begin(),(x).end()
#define debg(x) for(auto i: (x))cout<<i<<" "
#define fr first
#define sc second
#define rep(i, a, b) for (ll i = a; i < b; i++)
#define pryes cout << "YES\n"
#define prno  cout << "NO\n"  
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const int mod = 1e9 + 7;

void dfs(int root,vector<vector<int>>&adj,int parent){
	//cout<<root<<"->"<<parent<<"\n";
	for(auto i:adj[root]){
		if(i!=parent){
			dfs(i,adj,root);
		}
	}
}

void solve(){
    ll n;cin>>n;
    vector<vector<int>> adj (n);
    rep(i,0,n-1){
    	int a,b;
    	cin>>a>>b;
    	a--;b--;
    	adj[a].pb(b);
    	adj[b].pb(a);
    }
    
    dfs(0,adj,-1);
}

int main(){
    fastio
    ll TC;
    cin>>TC;
    while(TC--) solve();
    return 0;
}
