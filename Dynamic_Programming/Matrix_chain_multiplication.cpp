#include<bits/stdc++.h>
using namespace std;

int matrix_chain_multiplication(int matrix[], int n){
    int dp[n+1][n+1] = {0};     // diagonal are zero in place

    for(int l=2;l<=n;l++){
        for(int i=1;i+l-1<=n;i++){
            int cost = INT_MAX;
            for(int j=1;j<l;j++){  // place where the cut needs to be applied in 'l' length
                cost = min(cost, dp[i][i+j-1]+dp[i+j][i+l-1]+matrix[i-1]*matrix[i+j-1]*matrix[i+l-1]);
            }
            dp[i][i+l-1] = cost;
        }
    }
    return dp[1][n];
}

int main(){
    int matrix[] = {40, 20, 30, 10, 30};
    cout<<matrix_chain_multiplication(matrix,4);
    return 0;
}