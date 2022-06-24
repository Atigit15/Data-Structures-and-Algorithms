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

int n;
vvi v;
int node;
int diam=0;

void dfs(int root,int parent,int len){
	for(auto i:v[root]){
		if(i!=parent){
			dfs(i,root,len+1);
		}
	}
	if(len>diam) diam = len,node = root;
}

void solve(){
    cin>>n;
    v.resize(n);
    rep(i,0,n-1){
    	int a,b;
    	cin>>a>>b;
    	a--;b--;
    	v[a].pb(b);
    	v[b].pb(a);
    }
    dfs(0,-1,0);
    dfs(node,-1,0);
    cout<<diam;
}

int main(){
    fastio
    solve();
    return 0;
}