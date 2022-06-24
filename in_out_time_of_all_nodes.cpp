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

vector<pair<int,int>> in_out;
int timee=0;

void dfs(int root,vector<vector<int>>&adj,vector<bool> &vis){
	if(!vis[root]){
		vis[root]=1;
		in_out[root].fr = timee++;
		for(auto i:adj[root])
			dfs(i,adj,vis);
		in_out[root].sc = timee++;
	}
}

void solve(){
    ll n;cin>>n;
    vector<vector<int>> adj (n);
    vector<bool> vis(n,0);
    rep(i,0,n-1){
    	int a,b;
    	cin>>a>>b;
    	a--;b--;
    	adj[a].pb(b);
    	adj[b].pb(a);
    }
    in_out.resize(n);
    dfs(0,adj,vis);
    for(auto i:in_out)
    	cout<<i.fr<<" "<<i.sc<<"\n";
}

int main(){
    fastio
    solve();
    return 0;
}