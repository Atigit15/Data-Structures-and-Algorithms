//Everything we hear is an opinion, not a fact.
//Everything we see is a perspective, not the truth.

#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
const int mod = 1e9 + 7;

class MonotonicStack{
public:
	int n;
	vector<ll> arr;
	vector<ll> nextGr, nextSm;
	vector<ll> prevGr, prevSm;
	MonotonicStack (vector<ll> &arr) {
		n = arr.size();
		arr.resize(n);
		this->arr = arr;
		nextGr.resize(n);
		nextSm.resize(n);
		prevGr.resize(n);
		prevSm.resize(n);
		computeNextGr();
		computeNextSm();
		computePrevGr();
		computePrevSm();
	}
	void computeNextGr() {
		stack<int> st;
		st.push(0);
		for (int i = 1; i < n; i++) {
            if (st.empty()) {
                st.push(i);
                continue;
            }
            while (st.size() and arr[i] > arr[st.top()]) {
                nextGr[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        while (st.size()){
            nextGr[st.top()] = n ;
            st.pop();
        }
	}
	void computeNextSm() {
		stack<int> st;
		st.push(0);
		for (int i = 1; i < n; i++) {
            if (st.empty()) {
                st.push(i);
                continue;
            }
            while (st.size() and arr[i] < arr[st.top()]) {
                nextSm[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        while (st.size()){
            nextSm[st.top()] = n ;
            st.pop();
        }
	}
	void computePrevGr() {
		//previous gretear or equal
        stack<int> st;
        st.push(0);
        prevGr[0] = -1;
        for (int i = 1; i < arr.size(); i++) {
            while(st.size() and arr[i] > arr[st.top()]) {
                st.pop();
            }
            st.empty() ? prevGr[i] = -1 : prevGr[i] = st.top();
            st.push(i);
        }
	}
	void computePrevSm() {
		//previous smaller or equal
        stack<int> st;
        st.push(0);
        prevSm[0] = -1;
        for (int i = 1; i < arr.size(); i++) {
            while(st.size() and arr[i] < arr[st.top()]) {
                st.pop();
            }
            st.empty() ? prevSm[i] = -1 : prevSm[i] = st.top();
            st.push(i);
        }
	}
	
};

void solve(){
    ll n;cin>>n;
    vector<ll> v (n);
    for(int i=0;i<n;i++)
    	cin>>v[i];
    MonotonicStack ms (v);
    // cout << ms.nextGr.size() << " ";
    for(auto i : ms.nextGr) cout << i << " ";
    cout << "\n";
    for(auto i : ms.nextSm) cout << i << " ";
    cout<<"\n";
    for(auto i : ms.prevGr) cout << i << " ";
    cout<<"\n";
    for(auto i : ms.prevSm) cout << i << " ";
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll TC;cin>>TC;
    while(TC--) solve();
    return 0;
}

