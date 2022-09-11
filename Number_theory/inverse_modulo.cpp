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
int main(){
    cout<<inverse_modulo(6,7);
    return 0;
}