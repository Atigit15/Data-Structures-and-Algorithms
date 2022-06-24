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

pair<int,int> bfs(int root,vvi &v)
{
	int d = 0;
	queue<pair<int,int>> q;
	q.push({root, 0});
	vector<bool> vis(n, false);
	pair<int,int> u;
 
	while(!q.empty()) {
		u = q.front();
		vis[u.fr] = true;
		q.pop();
		for(int i : v[u.first])
			if(!vis[i])
			q.push({i, u.second + 1});
	}
	return u;
}

void solve(){
    cin>>n;
    vvi v (n); 
    rep(i,0,n-1){
    	int a,b;
    	cin>>a>>b;
    	a--;b--;
    	v[a].pb(b);
    	v[b].pb(a);
    }
    pair<int,int> end1 = bfs(0,v);
    pair<int,int> end2 = bfs(end1.fr,v);
    cout<<end2.sc<<"\n";
}

int main(){
    fastio
    solve();
    return 0;
}