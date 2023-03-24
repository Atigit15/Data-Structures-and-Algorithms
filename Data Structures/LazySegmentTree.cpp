#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
const int mod = 1e9 + 7;

//Credits : Milind Sharma

class LazySegmentTree{
public:
    vector <ll> tree;
    vector <ll> lazy;
    vector <ll> arr;
    ll n;
    LazySegmentTree(vector <ll> arr){
        this->arr = arr;
        n = arr.size();
        tree.resize(4*n,0);
        lazy.resize(4*n,0);
        build(1,0,n-1);
    }
    void propagate(ll i,ll l,ll r){
        if(l==r){
            tree[i] += lazy[i];
            lazy[i] = 0;
        }
        else{
            tree[i] += (r-l+1)*lazy[i];
            lazy[2*i] += lazy[i];
            lazy[2*i+1] += lazy[i];
            lazy[i] = 0;
        }
    }
    void build(ll i,ll l,ll r){
        if(l==r){
            tree[i] = arr[l];
            return;
        }
        ll mid = (l+r)/2;   
        build(2*i,l,mid);
        build(2*i+1,mid+1,r);
        tree[i] = tree[2*i] + tree[2*i+1];
    }
    void update(ll i,ll l,ll r,ll l1,ll r1,ll val){
        ll mid = (l+r)/2;
        propagate(i,l,r);
        if(l1>r || r1<l)
            return;
        if(l1<=l && r1>=r){
            lazy[i] += val;
            propagate(i,l,r);    
        }
        else{
            update(2*i,l,mid,l1,r1,val);
            update(2*i+1,mid+1,r,l1,r1,val);
            tree[i] = tree[2*i] + tree[2*i+1];
        }
    }
    void update(ll l,ll r,ll val){
        update(1,0,n-1,l,r,val);
    }
    ll query(ll i,ll l,ll r,ll l1,ll r1){
        ll mid = (l+r)/2;
        propagate(i,l,r);
        if(l1>r || r1<l)
            return 0;
        else if(l1<=l && r1>=r)
            return tree[i];
        ll left = query(2*i,l,mid,l1,r1);
        ll right = query(2*i+1,mid+1,r,l1,r1);
        return left + right;
    }
    ll query(ll l,ll r){
        return query(1,0,n-1,l,r);
    }
};

void solve(){
    ll n;cin>>n;
    vector<ll> v (n);
    for(int i=0;i<n;i++)
    	cin>>v[i];
    LazySegmentTree st  (v);
    cout<<st.query(0,3)<<"\n";
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll TC;cin>>TC;
    while(TC--) solve();
    return 0;
}