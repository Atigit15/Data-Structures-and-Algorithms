#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
const int mod = 1e9 + 7;

/*
	https://cp-algorithms.com/data_structures/disjoint_set_union.html
	Path compression optimisation
	Union by size
	O(1) average time complexity (after optimisations)
*/

class DSU{
public:
	ll connected;
	vector<ll> par,sz;
	DSU(ll n) {
		par.resize(n,1);
		iota(par.begin(),par.end(),0);
		sz.resize(n,1);
		connected=n;
	} 
	ll getPar(ll k){
		if (k == par[k])
    		return k;
		return par[k] = getPar(par[k]);
	}
	ll getSize(ll k){
		return sz[getPar(k)];
	}
	void unite(ll u, ll v){
		ll par1=getPar(u), par2=getPar(v);
		if(par1==par2)
			return;
		connected--;
		if(sz[par1]>sz[par2])
			swap(par1, par2);
		sz[par2]+=sz[par1];
		sz[par1]=0;
		par[par1]=par[par2];
	}
};

void solve(){
    ll n;cin>>n;
    vector<ll> v (n);
    for(int i=0;i<n;i++)
    	cin>>v[i];
    DSU dsu = DSU (n);
    
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll TC;cin>>TC;
    while(TC--) solve();
    return 0;
}