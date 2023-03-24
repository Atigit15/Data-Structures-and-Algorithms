#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

//credits : MilindSharma

class SegmentTree{
public:
    vector<ll> tree;
    vector<ll> arr;
    ll n;
	//constructor
    SegmentTree(vector<ll> arr){
        this->arr = arr;
        n = arr.size();
        tree.resize(4*n,0);
        build(1,0,n-1);
    }
    //build tree
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
    void update(ll i,ll pos,ll l,ll r,ll number){
        ll mid = (l+r)/2;
        if(l==r){
            tree[i] = number;
            return;
        }
        else if(pos<=mid)
            update(2*i,pos,l,mid,number);
        else
            update(2*i+1,pos,mid+1,r,number);
        tree[i] = tree[2*i] + tree[2*i+1];
    }
    //update the value at pos to number
    void update(ll pos,ll number){
        update(1,pos,0,n-1,number);
    }
    ll query(ll i,ll l,ll r,ll l1,ll r1){
        ll mid = (l+r)/2;
        if(l1>r || r1<l)
            return 0;
        else if(l1<=l && r1>=r)
            return tree[i];
        ll left = query(2*i,l,mid,l1,r1);
        ll right = query(2*i+1,mid+1,r,l1,r1);
        return left + right;
    }
    //returns req_operation([l,r])
    ll query(ll l,ll r){
        return query(1,0,n-1,l,r);
    }
};

void solve(){
    ll n;cin>>n;
    vector<ll> v (n);
    for(int i=0;i<n;i++)
    	cin>>v[i];
    SegmentTree st = SegmentTree(v);
	//0-based
    cout<<st.query(0,3)<<"\n";
}

int main(){
    fastio
    ll TC;
    cin>>TC;
    while(TC--) solve();
    return 0;
}