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

vi spf;
void sievespf(ll n) {
	spf.resize(n+1,0);
    for (ll i=1; i<=n; i++)
        spf[i] = i;

    for (ll p=2; p*p<=n; p++) {
        if (spf[p] == p) {
            for (ll i=p*p; i<=n; i += p) 
                if (spf[i]==i)
                	spf[i]=p; 
        }
    } 
} 

void solve(){
    ll n;cin>>n;
    while(n>1){
    	ll y = spf[n];
    	ll cnt=0;
    	while(n%y==0){
    		n /= y;
    		cnt++;
    	}
    	cout<<y<<" "<<cnt<<"\n";
    }
    cout<<"\n";
}

int main(){
    fastio
    sievespf(1e6);
    ll TC;
    cin>>TC;
    while(TC--) solve();
    return 0;
}