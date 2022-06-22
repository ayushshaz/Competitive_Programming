#include<bits/stdc++.h>
using namespace std;

int rod_cutting(int length[], int price[], int n, int rod){
    int ans=0;
    for(int i=0;i<n;i++){
        if(rod-length[i]>=0){
            ans = max(ans,rod_cutting(length,price,n,rod-length[i])+price[i]);
        }
    }
    return ans;
}

//Bottom-Up
int rod_cuttingBU(int length[], int price[], int n, int rod){
    int dp[100][100]={0};
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            dp[i][j]=dp[i-1][j];
            if(j-length[i-1]>=0){
                dp[i][j] = max(dp[i][j],max(dp[i-1][j-length[i-1]]+price[i-1],dp[i][j-length[i-1]]+price[i-1]));
            }
        }
    }
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=n;j++){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    return dp[n][n];
}

int main(){
    int length[]={1,2,3,4,5,6,7,8};
    int price[]={1,5,8,9,10,17,17,20};
    cout<<rod_cuttingBU(length,price,8,8);
    return 0;
}