#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
const int mod = 1e9 + 7;

/*
		Mo's Algorithm for answering offline queries
		https://cp-algorithms.com/data_structures/sqrt_decomposition.html
		Credits : https://ncduy0303.github.io/
		Time complexity: O(n*sqrt(n))
		Problem link: https://cses.fi/problemset/task/1734
*/

const int MAX_N = 2e5 + 1;
const int INF = 1e9;
const ll LINF = 1e18;

struct query{
    int SQRT = 500;
    int l, r, id;
    bool operator< (query b) {
        query a = *this;
        return array<int,2>{a.l/SQRT, a.r} < array<int,2>{b.l/SQRT, b.r};
    }
};

int n, q, arr[MAX_N], ans[MAX_N], cnt[MAX_N], cur;
query qs[MAX_N];

void add(int idx) {
    if (cnt[arr[idx]] == 0) cur++;
    cnt[arr[idx]]++;
}
 
void subtract(int idx) {
    if (cnt[arr[idx]] == 1) cur--;
    cnt[arr[idx]]--;
}

// compress used values from 1e9 to 2e5 
void compress() {
    map<int, int> mp;
    for (int i = 1; i <= n; i++) 
        mp[arr[i]] = i;
    for (int i = 1; i <= n; i++) 
        arr[i] = mp[arr[i]];
}

void mo_algo() {
    sort(qs + 1, qs + n + 1);
    int curL = 0, curR = 0;
    add(0);
    for (int i = 1; i <= n; i++) {
        int L = qs[i].l, R = qs[i].r;
        while (curL < L) subtract(curL++);
        while (curL > L) add(--curL);
        while (curR < R) add(++curR);
        while (curR > R) subtract(curR--);
        ans[qs[i].id] = cur;
    }
}

void solve() {
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    compress();
    for (int i = 1; i <= q; i++) {
        cin >> qs[i].l >> qs[i].r;
        qs[i].id = i;
    }
    mo_algo();
    for (int i = 1; i <= q; i++) 
        cout << ans[i] << "\n";
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    // ll TC;cin>>TC;
    // while(TC--) 
    	solve();
    return 0;
}