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
const int MOD = 1e9 + 7;


void solve(){
    ll n;cin>>n;
    vi v (n);
    rep(i,0,n){
    	cin>>v[i];
    }
    //[](int i) {cout << ":" << i << ":";}(42);
    //for_each(all(v),[](int i){cout<<i<<" ";}(42));
    
    cout << "This lambda returns " << 
	[] (int x, int y){
	if(x > 5)
		return x + y;
	else if (y < 2)
		return x - y;
	else
		return x * y;
	}
	(4, 3) << endl;
	
    cout << "This lambda returns " << [](double x, double y) -> int {return x + y;} (3.14, 2.7) << endl;
}

int main(){
    fastio
    ll TC;
    cin>>TC;
    while(TC--) solve();
    return 0;
}