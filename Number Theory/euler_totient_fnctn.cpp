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

ll phi(ll n){  // O(sqrt(n))
	ll number = n;
	if (n % 2 == 0){
		number /= 2;
		while (n % 2 == 0)
			n /= 2;
	} 
	for (ll i = 3; i <= sqrt(n); i += 2){
		if (n % i == 0){
			while (n % i == 0)
				n /= i;
			number = (number / i * (i - 1));
		}
	}
	if (n > 1)
		number = (number / n * (n - 1));
		
	return number;
}

void solve(){
    ll n;cin>>n;
    cout<<phi(n)<<"\n";
}

int main(){
    fastio
    ll TC;
    cin>>TC;
    while(TC--) solve();
    return 0;
}