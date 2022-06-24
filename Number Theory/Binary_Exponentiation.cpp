\#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long int
#define rep(i, a, b) for (ll i = a; i < b; i++) 
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const int mod = 1e9 + 7;

//If 'm' is a prime number we can speed up this algorithm by calculating x^(n*(m-1)) instead of x^n.
//Fermats Little Theorem

// calculate a^b in O(logn) time
ll binpow(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

// calculate (a^b)%m in O(logn) time
ll binpow(ll a, ll b, ll m) {
    a %= m;
    ll res = 1;
    while (b > 0) {
        if (b & 1) res = (res * a) % m;
        a = (a * a) % m;
        b >>= 1;
    }
    return res;
}

int main(){
    fastio
    ll a,b;
    cin>>a>>b;
    cout<<binpow(a,b)<<" ";
    cout<<binpow(a,b,mod);
    return 0;
}
