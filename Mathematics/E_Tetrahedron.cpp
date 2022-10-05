#include<bits/stdc++.h>
using namespace std;

#define ld long double
#define F first
#define S second
#define pb push_back
#define P pair<int, int>

const int N = 1e7+5;
const int32_t M=1e9+7;

int dp[4][N];

void solve(){
    int n; cin>>n;
    dp[0][0]=0;
    dp[1][0]=0;
    dp[2][0]=0;
    dp[3][0]=1;// for D
    
    for(int i=1;i<=n;i++){
        long long sum = 1ll*dp[0][i-1]+dp[1][i-1]+dp[2][i-1]+dp[3][i-1];
        for(int j=0;j<4;j++){
            dp[j][i] = ((sum - dp[j][i-1])%M + M)%M;
        }
    }
    cout<<dp[3][n]<<"\n";
}
	
int32_t main(){
	solve();
	return 0;
}