#include<bits/stdc++.h>
using namespace std;

#define ll long long
const ll mod = 1000000007LL;

int power(int a, int b) {
  int result = 1;
  while (b) {
    if (b & 1)
      result = (result * a) % mod;
    a = (a * a) % mod;
    b /= 2;
  }
  return result;
}

int fact[1000005];
int inv[1000005];

void precompute() {
  fact[0] = 1;
  fact[1] = 1;
  for (int i = 2; i <= 1000004; i++)
    fact[i] = (fact[i - 1] * i) % mod;
  inv[1000004] = power(fact[1000004], mod - 2);
  for (int i = 1000003; i >= 0; i--)
    inv[i] = ((i + 1) * inv[i + 1]) % mod;
}

int ncr(int n, int r) {
  if (r > n || r < 0 || n < 0)
    return 0;
  int x = (fact[n] * inv[r]) % mod;
  return (x * inv[n - r]) % mod;
}




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