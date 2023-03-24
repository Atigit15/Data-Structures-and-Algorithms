#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long int
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int,int>
#define vii vector<pii>
#define pryes cout<<"YES"<<"\n";
#define prno cout<<"NO"<<"\n";
#define rep(i, a, b) for (int i = a; i < b; i++)
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const int MOD = 1e9 + 7;

void solve(){
    string q;
    getline(cin>>ws,q);
    stringstream ss (q);
    string word;
    bool flag = 0;
    while(ss >> word){
        string p;
        if(!flag) {
            if(word.size()!=1)
            {word[0] += 32;word[1] -= 32;flag=1;}
        }
        p = word.substr(1,word.size()-1) + word[0] + "ay";
        cout<<p<<" ";
    }
    cout<<"\n";
}

int main(){
    fastio
    ll TC;
    cin>>TC;
    while(TC--){
        solve();
    }
    return 0;
}
