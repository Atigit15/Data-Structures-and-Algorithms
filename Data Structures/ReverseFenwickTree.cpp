#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
const int mod = 1e9 + 7;

class FenwickTree{
public :
	vector<ll> tree;
	ll n;
	FenwickTree(vector<ll> &v){
		n = v.size();
		tree.resize(n+1,0);
		// for(ll i=0;i<v.size();i++){
			// update(i+1,v[i]);
		// }
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
    FenwickTree fw = FenwickTree (v);
    while(q--){
    	ll a;cin>>a;
    	if(a==1){
    		ll b,c,d;cin>>b>>c>>d;
    		fw.update(b,d);
    		fw.update(c+1,-d);
    	}
    	else{
    		ll b;cin>>b;
    		cout<< v[b-1] + fw.sum(b) << "\n"; 
    	}
    }
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}