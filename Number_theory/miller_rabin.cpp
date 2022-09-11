#include<bits/stdc++.h>
using namespace std;

int modular_multiplication(int a, int b, int n){
    int res=0;
    while(b){
        if(b&1ll) res+=a;
            a*=2;
            b/=2;
            res%=n;
            a%=n;
    }
    return res;
}
int modular_exponentiation(int a, int b, int n){    // a^b % n
    int res=1;
    while(b){
        if(b&1ll){
            // res=res*a;
            // res%=n;
            res = modular_multiplication(res,a,n);
        }
        // a*=a;
        a = modular_multiplication(a,a,n);
        a%=n;
        b/=2;
    }
    return res;
}

bool miller_rabin(int n){   // cheks it is prime or not in (9*logn)
    if(n==1) return false;
    if(n==2) return true;
    if(n%2==0) return false;
    int d=n-1, s=0;
    while(d%2==0){
        s++;
        d/=2;
    }
    vector<int> a({2,3,5,7,11,13,17,19,23});
    for(int i=0; i<a.size();i++){
        if(a[i]>n-2) continue;
        int ad = modular_exponentiation(a[i],d,n);
        if(ad % n == 1) continue;
        bool prime = false;
        for(int r=0;r<=s-1;r++){
            int rr = modular_exponentiation(2,r,n);
            int ard = modular_exponentiation(ad,rr,n);
            if(ard%n==n-1){
                prime = true;
                break;
            }
        }
        if(prime==false) return false;
    }
    return true;
}

int main(){
    int t;cin>>t;
    while(t--){
        int n; cin>>n;
        if(miller_rabin(n)){
            cout<<"Prime\n";
        }else{
            cout<<"Not Prime\n";
        }
    }
    return 0;
}