#include<bits/stdc++.h>
using namespace std;
//top down
int minCoin(int n, int coins[],int t, int dp[]){
    if(n==0){
        return 0;
    }
    if(dp[n]!=0){
        return dp[n];
    }
    int ans=INT_MAX;
    for(int i=0;i<t;i++){
        if(n=coins[i]>0){
            int subans = minCoin(n-coins[i],coins,t,dp);
            ans = min(ans,subans+1);
        }
    }
    dp[n] = ans;
    return ans;
}
//bottom-up
int minCoinsBU(int n, int coins[],int t){
    int dp[100]={0};
    for(int i=1;i<=n;i++){
        dp[i] =INT_MAX;
        for(int j=0;j<t;j++){
            if(n-coins[j]>=0){
                dp[i]= min(dp[i],dp[i-coins[j]]+1);
            }
        }
    }
    return dp[n];
}

int main(){
    int n=15;
    int coins[] = {1,7,10};
    int dp[100] = {0};

    return 0;
}