#include<bits/stdc++.h>
using namespace std;

int costOfWine(int *wines,int i, int j, int year){
    if(i==j){
        return wines[i]*year;
    }
    int ans=0;
    ans = max(costOfWine(wines,i,j-1,year+1)+wines[j]*year,costOfWine(wines,i+1,j,year+1)+wines[i]*year);
    return ans;
}

int costOfWineBU(int wines[], int n){
    int dp[n][n] = {0};
    int year = n;
    for(int l=1;l<=n;l++){
        for(int i=0;i+l-1<n;i++){
            if(l==1){ //base case
                dp[i][i+l-1] = wines[i]*year;
            }else{
                dp[i][i+l-1] = max(wines[i]*year+dp[i+1][i+l-1], wines[i+l-1]*year+dp[i][i+l-2]);
            }
        }
        year--;
    }
    return dp[0][n-1];
}

int main(){
    int wines[] = {2,3,5,1,4};
    cout<<costOfWineBU(wines,5)<<endl;
    cout<<costOfWine(wines,0,4,1);
    return 0;
}