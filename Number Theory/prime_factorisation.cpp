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

map<ll,ll> primefact(ll n){
    map<ll,ll> m;
    for(ll i=2;i*i<=n;i++){
    	if(n%i==0){
    		ll cnt=0;
    		while(n%i==0){
    			cnt++;
    			n /= i;
    		}
    		m[i] = cnt;
    	}
    }
    if(n>1) m[n]=1;
    return m;
}

void solve(){
    ll n;cin>>n;
    map<ll,ll> ans = primefact(n);
    for(auto i:ans)
    	cout<<i.fr<<" "<<i.sc<<"\n";
}

int main(){
    fastio
    solve();
    return 0;
}