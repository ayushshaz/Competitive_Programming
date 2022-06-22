#include<bits/stdc++.h>
using namespace std;

int lcs(string s, string p, int i, int j){
    if(i==s.length() or j== p.length()){
        return 0;
    }
    if(s[i]==p[j]){
        return 1+lcs(s,p,i+1,j+1);
    }
    return max(lcs(s,p,i+1,j),lcs(s,p,i,j+1));
}

//bottom up
int lcs_BU(string s, string p, int i, int j){
    int dp[100][100]={0};
    for(int i=1;i<=s.length();i++){
        for(int j=1;j<=p.length();j++){
            if(s[i]==p[j]){
                dp[i][j]=dp[i-1][j-1]+1;
            }
            dp[i][j] = max(dp[i][j],dp[i-1][j]);    
            dp[i][j] = max(dp[i][j],dp[i][j-1]);
        }
    }
    return dp[s.length()][p.length()];
}

int main(){
    string a = "ABCD";
    string b = "ABCDE";
    cout<<lcs(a,b,0,0)<<endl;
    cout<<lcs_BU(a,b,0,0);
    return 0;
}