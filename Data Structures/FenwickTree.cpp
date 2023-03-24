#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
const int mod = 1e9 + 7;

/*	https://cp-algorithms.com/data_structures/fenwick.html
          Update and Sum operations - O(log n)
		  Point Update Range Query
		  Range Update Point Query (backward BIT)
		  Range Update Range Query
*/
class FenwickTree{
public :
	vector<ll> tree;
	ll n;
	FenwickTree(vector<ll> &v){
		n = v.size();
		tree.resize(n+1,0);
		for(ll i=0;i<v.size();i++){
			update(i+1,v[i]);
		}
	}
	//increase array value at idx by val
	void update(ll idx,ll val){
		while(idx <= n){
			tree[idx] += val;
			idx += (idx & -idx);
		}
	}
	//returns sum(1,idx)
	ll sum(ll idx){
		ll s = 0;
		while(idx >= 1){
			s += tree[idx];
			idx -= (idx & -idx);
		}
		return s;
	}
	//return sum(l,r);
	ll rdq(ll l,ll r){
		return sum(r) - sum(l-1);
	}
};


void solve(){
    ll n,q;cin>>n>>q;
    vector<ll> v (n);
    for(int i=0;i<n;i++)
    	cin>>v[i];
    FenwickTree fw = FenwickTree(v);
    while(q--){
    	ll a,b,c;
    	cin>>a>>b>>c;
    	if(a==1) fw.update(b,c-fw.rdq(b,b));
    	else cout<<fw.rdq(b,c)<<"\n";
    }  
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll TC;cin>>TC;
    while(TC--) solve();
    return 0;
}