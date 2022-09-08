#include<bits/stdc++.h>
using namespace std;

bool isPrime(int n){
    for(int i=2;i*i<n;i++){
        if(n%i == 0){
            return false;
        }
    }
    return true;
}
// sieve limitation is 10^7 (nlog(logn))
void prime_sieve(int *p){
    // mark all odd number as prime
    for(int i=3;i<=10000;i+=2){
        p[i]=1;
    }
    //sieve 
    for(int i=3; i<=10000;i+=2){
        if(p[i]==1){
            // Mark all multiples of i as non-prime
            for(long long int j=i*i; j<=10000; j=j+i){
                p[j]=0;
            }
        }
    }
    // Special case
    p[2]=1;
    p[1]=p[0]=0;
}

bitset<100005> b;   // 8 times less memory used here
vector<int > prime;
void bitset_sieve(int n){ // till n
    b.set();
    b[0]=b[1]=0;
    for(long long int i=2;i<=n;i++){
        if(b[i]){
            cout<<i<<" "; // or pushback in prime vector
            for(long long int j=i*i; j<=n; j=j+i){
                b[j]=0;
            }
        }
    }
}

int main(){
    int t;cin>>t;
    while(t--){
        int n; cin>>n;
        int p[100005] = {0};
        prime_sieve(p);

        // print prime upto range n
        for(int i=0;i<=n;i++){
            if(p[i]==1){
                cout<<i<<" ";
            }
        }
        cout<<endl;
        bitset_sieve(n);
    }
    return 0;
}