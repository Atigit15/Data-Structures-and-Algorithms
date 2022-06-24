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

// timec O(nlog(log(n)))
vector<bool> primes; //tells whether a no is prime or not
vector<int> pr; //contains primes

void sieve(ll n){
	primes.resize(n+1,1);
	primes[0]=primes[1]=false;
	rep(i,2,n+1){
		if(primes[i]){
			pr.pb(i);
			for(ll j=i*i;j<n+1;j+=i){
				primes[j]=0;
			}
		}
	}
	debg(pr);
}

void solve(){
    ll n;cin>>n;
    //proccess
}

int main(){
    fastio
    sieve(20);
    solve();
    return 0;
}