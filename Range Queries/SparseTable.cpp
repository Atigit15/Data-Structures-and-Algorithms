#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

//https://cp-algorithms.com/data_structures/sparse-table.html
//Sparse Table - O(1) Query Answer after O(nlogn) Precomputing
//Space - O(nlogn)
//Can be used only on Static Arrays
//Idempotent/Overlap Friendly functions - min,max,gcd,and,or
//Credits to : MilindSharma

class SparseTable{
    private:
        vector<vector<ll>> MinTable,MaxTable;
        vector<ll> log;
    public:
        SparseTable(vector<ll> arr){
            ll n = arr.size();
            ll k = log2(n);
            MinTable.resize(k+1,vector<ll>(n,0));
            MaxTable.resize(k+1,vector<ll>(n,0));
            log.resize(n+1);
            MinTable[0] = arr;
            MaxTable[0] = arr;
            for(ll i=1;i<=k;i++){
                for(ll j=0;j<=n-(1LL<<i);j++){
                    MinTable[i][j] = min(MinTable[i-1][j],MinTable[i-1][j+(1LL<<(i-1LL))]);
                    MaxTable[i][j] = max(MaxTable[i-1][j],MaxTable[i-1][j+(1LL<<(i-1LL))]);
                }
            }
            for(ll i=1;i<=n;i++)
                log[i] = log2(i);
        }
        ll queryMIN(ll l,ll r){
            ll k = log[r-l+1];
            return min(MinTable[k][l-1],MinTable[k][r-(1LL<<k)]);
        }
        ll queryMAX(ll l,ll r){
            ll k = log[r-l+1];
            return max(MaxTable[k][l-1],MaxTable[k][r-(1LL<<k)]);
        }
};

void solve(){
    ll n;cin>>n;
    vector<ll> v (n);
    for(int i=0;i<n;i++)
    	cin>>v[i];
    SparseTable ST (v);
    ll ansmin = ST.queryMIN(2,3); //1-based
    ll ansmax = ST.queryMAX(2,3);
    cout<<ansmin<<" "<<ansmax<<"\n";
}

int main(){
    fastio
    ll TC;
    cin>>TC;
    while(TC--) solve();
    return 0;
}
