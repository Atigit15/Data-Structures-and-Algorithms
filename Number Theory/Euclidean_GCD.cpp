#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int gcd(int a,int b){               //Euclidean Theorem.
    if(a==0) return b;
    return gcd(b%a,a);
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int a,b;
    cin>>a>>b;;
    cout<<gcd(a,b)<<endl;
    return 0;
}