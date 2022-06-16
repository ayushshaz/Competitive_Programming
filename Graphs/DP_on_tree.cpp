#include<bits/stdc++.h>
using namespace std;

const int N = 10005;
vector<int> gr[N];
bool visited[N];
int dp[N];

void dfs(int v){
    visited[v]=true;
    dp[v]=v;
    for(auto nbr: gr[v]){
        if(!visited[nbr]){
            dfs(nbr);
            dp[v] = min(dp[v],dp[nbr]);
        }
    }
}

int main(){ //minimum in the subtree
    int n;cin>>n;
    for(int i=1;i<n;i++){
        int x,y; cin>>x>>y;
        gr[x].push_back(y);
        gr[y].push_back(x);
    }
    dfs(1);
    for(int i=1;i<=n;i++){
        cout<<i<<" "<<dp[i]<<"\n";
    }
    return 0;
}