#include<bits/stdc++.h>
using namespace std;

long long solveCellProblem(int n, int x, int y, int z){
    long long *dp = new long long[n+1];
    dp[0]=0;
    dp[1]=1;
    for(int i=2;i<=n;i++){
        if(i%2==0){
            dp[x]=min(dp[i/2]+x,dp[i-1]+y);
        }else{
            dp[x]=min(dp[(i+1)/2]+x+z,dp[i-1]+y);
        }
    }
    return dp[n];
}

int main(){
    int n,x,y,z; cin>>n>>x>>y>>z;
    cout<<solveCellProblem(n,x,y,z);
    return 0;
}