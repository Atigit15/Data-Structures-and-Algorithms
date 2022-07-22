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

class BinaryLifting {
	public:
		ll n,maxLog,maxRequirement;
		vector<vector<ll>> parent;
		vector<ll> logValues;
		bool precomputedLogs = false;
		
		BinaryLifting(){}

		BinaryLifting(ll n1, vvi& edges, ll requirement, ll root) {
			n = n1;
			parent.resize(n);
			maxLog = log2(requirement + 1);
			maxRequirement = requirement;
			for (ll i = 0; i < n; i++) {
				parent[i].resize(maxLog + 1);
				for (ll j = 0; j <= maxLog; j++) {
					parent[i][j] = -1;
				}
			}
			fillParentTable(root, edges);
			if (maxRequirement <= 1000000LL)
				precomputeLogs();
		}
		void fillParentTable(ll root, vvi& edges) {
			vector<bool> visited(n);
			dfsBinaryLifting(root, edges, visited);
			ll intermediate = -1;
			for (ll i = 1; i <= maxLog; i++) {
				for (ll j = 0; j < n; j++) {
					intermediate = parent[j][i - 1];
					if (intermediate != -1) {
						parent[j][i] = parent[intermediate][i - 1];
					}
				}
			}
		}
		void dfsBinaryLifting(ll root, vvi &edges, vector<bool> &visited) {
			visited[root] = true;
			for (auto i : edges[root]) {
				if (!visited[i]) {
					parent[i][0] = root;
					dfsBinaryLifting(i, edges, visited);
				}
			}
		}
		void precomputeLogs() {
			precomputedLogs = true;
			logValues.resize(maxRequirement + 1);
			logValues[1] = 0;
			for (ll i = 2; i <= maxRequirement; i++) {
				logValues[i] = logValues[i / 2] + 1;
			}
		}
		ll kthParent(ll start, ll k) {
			ll a = start;
			while (k > 0) {
				ll x = getLog(k);
				a = parent[a][x];
				if (a == -1)
					return a;
				k -= (1 << x);
			}
			return a;
		}
		inline ll getLog(ll x) {
			return precomputedLogs ? logValues[x] : log2(x);
		}
};

class LCA {
	private:
		ll n;
		vector<ll> level;
		vector<vector<ll>> edges;
		BinaryLifting bl_object;
		void dfsLCA(ll root, ll parent) {
			for (auto i : edges[root]) {
				if (i != parent) {
					level[i] = level[root] + 1;
					dfsLCA(i,root);
				}
			}
		}
	public:
		LCA(ll n, vvi& edges, ll root) {
			this->edges = edges;
			this->n = n;
			this->bl_object = BinaryLifting(n,edges,1e6,0);
			level.resize(n);
			dfsLCA(root, -1);
			
		}
		ll getLCA(ll a, ll b) {
			if (level[a] > level[b]) {
				swap(a, b);
			}
			b = bl_object.kthParent(b, level[b] - level[a]);
			if (a == b) return a;
			for (ll i = bl_object.maxLog; i >= 0; i--) {
				ll parent1 = bl_object.parent[a][i];
				ll parent2 = bl_object.parent[b][i];
				if (parent2 != parent1 && parent1 != -1 && parent2 != -1) {
					a = parent1;
					b = parent2;
				}
			}
			return bl_object.parent[a][0];
		}
		ll getLevel(ll a) {
			return level[a];
		}
};

void solve(){
    ll n,q;cin>>n>>q;
    vvi v (n);
    rep(i,0,n-1){
    	ll a,b;
    	cin>>a>>b;
    	a--;b--;
    	v[a].pb(b);
    	v[b].pb(a);
    }
    LCA lca = LCA (n,v,0);
    while(q--){
    	ll a,b;
    	cin>>a>>b;
    	a--;b--;
    	ll sum1 = lca.getLevel(a);
    	ll sum2 = lca.getLevel(b);
    	ll sum3 = lca.getLevel(lca.getLCA(a,b));
    	cout<<sum1+sum2-2*sum3<<"\n";
    }
}

int main(){
    fastio
    solve();
    return 0;
}