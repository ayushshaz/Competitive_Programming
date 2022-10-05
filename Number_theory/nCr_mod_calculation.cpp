#include<bits/stdc++.h>
using namespace std;

int x,y,gcd_value;    //ax+by=gcd
void extended_euclid(int a,int b){ // Extended
    if(b==0){   // reached last
        x=1;
        y=0;
        gcd_value = a;
        return;
    }
    extended_euclid(b,a%b);
    int cx = y;
    int cy = x-(a/b)*y;
    x = cx;
    y = cy;
    // cout<<x<<" "<<y<<endl;
}

int inverse_modulo(int a, int m){
    extended_euclid(a,m);
    return (x+m)%m;
}

double combination(int n, int r, int mod){
    double ans = 1;
    for(int i=1;i<=r;i++){
        ans = fmod((fmod(fmod(ans,mod)*fmod(n-i+1,mod),mod)*((double)inverse_modulo(i,mod))),mod);
    }
    return ans;
}
int main(){
    int mod = 998244353; // mod has to be a prime or else it might give wrong answer
    int t;cin>>t;
    while(t--){
        cout<<combination(5,3,11)<<endl;
    }
    return 0;
}