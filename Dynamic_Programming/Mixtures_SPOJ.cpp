#include<bits/stdc++.h>
using namespace std;

int minimum_smoke(int arr[], int n){
    int dp[n+1][n+1]={0};
    int prefix[n]={0};

    int sum=0;
    for(int i=1;i<=n;i++){
        sum+=arr[i-1];
        prefix[i]=sum;
    }

    for(int l=2;l<=n;l++){
        for(int i=1;i+l-1<=n;i++){
            int smoke = INT_MAX;
            for(int cut=1;cut<l;cut++){
                //i, i+cut, i+l-1 ------->  left, joint position[right], right respectively
                smoke = min(smoke,dp[i][i+cut-1]+dp[i+cut][i+l-1]+((prefix[i+cut-1]-prefix[i-1])%100)*((prefix[i+l-1]-prefix[i+cut-1])%100));
            }
            dp[i][i+l-1]=smoke;
        }
    }
    return dp[1][n];
}
int main(){
    int n;
    while(cin>>n){
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        cout<<minimum_smoke(arr,n)<<endl;
    }
    return 0;
}