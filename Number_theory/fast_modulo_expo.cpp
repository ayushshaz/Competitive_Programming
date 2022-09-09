#include<bits/stdc++.h>
using namespace std;

#define ll long long 
ll fastModExp(ll a, ll b){  // a^b
    
    ll res = 1;
    while(b>0){
        if(b&1){
            res = res*a;
        }
        a = a*a;
        b = b>>1;
    }
    return res;
}

int main(){
    cout<<fastModExp(2,3); 
    return 0;
}