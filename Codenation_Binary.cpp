#include <iostream>
using namespace std;

int gcd(int a, int b){
    return b == 0 ? a : gcd(b, a % b);   
}

int gcd_Extended(int a, int b, int* x, int* y){
    if (a == 0){
        *x = 0, *y = 1;
        return b;
    }
    int x1, y1;
    int gcd = gcd_Extended(b % a, a, &x1, &y1);
    *x = y1 - (b / a) * x1;
    *y = x1;
    return gcd;
}

int mod_inverse(int a, int m){
    int x, y, res;
    int g = gcd_Extended(a, m, &x, &y);
    if (g != 1){
        cout << "Inverse doesn't exist";
    }else{
        res = (x % m + m) % m;
    }
    return res;
}

int get_all_mids(int n){
    if(n<=0){
        return 0;
    }
    if(n==1){
        return 0;
    }
    int ans=0;
    if(n&1){
        ans = 2*get_all_mids((n-1)/2)+1;
    }else{
        ans = get_all_mids(n/2)+get_all_mids((n-1)/2)+1;
    }
    return ans;
}

int main() {
    int l,r; cin>>l>>r;
    int mids = get_all_mids(r-l+1);
    int total = r-l+1;
    int gcd_value = gcd(mids,total);
    mids = mids/gcd_value;
    total = total/gcd_value;
    int ans;
    if(mids>0){
        ans = mids*mod_inverse(total,1000000007);
    }else{
        ans=1;
    }
    cout<<ans;
   return 0;
}
