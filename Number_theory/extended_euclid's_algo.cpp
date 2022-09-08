#include<bits/stdc++.h>
using namespace std;

int gcd(int a,int b){  //Euclid
    return b==0 ? a: gcd(b,a%b);
}

int x,y,gcd_value;    //ax+by=gcd
void extended_euclid(int a,int b){ // Extended
    if(b==0){   // reached last
        x=1;
        y=0;
        gcd_value = a;
    }
    extended_euclid(b,a%b);
    int cx = y;
    int cy = x-(a/b)*y;
    x = cx;
    y = cy;
}

int main(){
    extended_euclid(18,30);
    cout<<x<<" "<<y<<endl;
    return 0;
}