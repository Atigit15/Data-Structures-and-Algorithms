#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long int
#define vi vector<int>
#define vvi vector<vi>
#define all(x) (x).begin(),(x).end()
#define debg(x) for(auto i: (x))cout<<i<<" "
#define fr first
#define sc second
#define rep(i, a, b) for (int i = a; i < b; i++)
#define pryes cout << "YES\n"
#define prno  cout << "NO\n"  
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const int MOD = 1e9 + 7;

int egcd(int a, int b, int& x, int& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = egcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

void solve(){
    int a,b,x,y;
    cin>>a>>b;
    int t = egcd(a,b,x,y);
    cout<<t<<" "<<x<<" "<<y<<"\n";
}

int main(){
    fastio
    solve();
    return 0;
}