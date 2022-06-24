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

vi fact;
//vi invfact;

ll expo(ll a, ll b, ll mod) {
	ll res = 1;
	while (b > 0){
		if (b & 1) res = (res * a) % mod; 
		a = (a * a) % mod; 
		b = b >> 1;
	} 
	return res;
}
ll modinverse(ll a, ll b) { return expo(a, b - 2, b); }

void computefact(ll n){
	fact.resize(n+1);
	fact[0]=1;
	rep(i,1,n+1){
		fact[i] = (fact[i-1]*(i%mod))%mod;	
		//invfact[i] = modinverse(fact[i],mod);	
	}
}
 
ll C(ll n,ll r,ll mod){
    if (n < r) return 0;
    if (r == 0) return 1;
    return ((fact[n]* (modinverse(fact[r],mod)))%mod * (modinverse(fact[n-r],mod))) % mod;
    //return ((fact[n]* infact[r])%mod * (invfact[n-r])) % mod;
}

//binomial coeffecient no mod
ll C(ll n, ll k) {
  	ll ans=1;
  	rep(i,0,k){
  		ans *= n-i;
  		ans /= i+1;
  	}
  	return ans;
}

void solve(){
    ll n;cin>>n;
    cout<<C(n,2,mod)<<" ";
}

int main(){
    fastio
    computefact(1000000);
    ll TC;
    cin>>TC;
    while(TC--) solve();
    return 0;
}