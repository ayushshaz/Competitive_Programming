#include<bits/stdc++.h>
using namespace std;

const int N = 10005;
vector<int> gr[N];
bool visited[N];
int dp[N],depth[N];

void dfs(int v,int par,int d){
    visited[v]=true;
    depth[v]=d;
    dp[v]=d;
    for(auto nbr: gr[v]){
        if(!visited[nbr]){
            dfs(nbr,v,d+1);
            dp[v] = min(dp[v],dp[nbr]);
        }else if(nbr!=par){ // there is backedge
            dp[v] = min(dp[v],depth[nbr]);
        }
    }
}

int main(){ // find the smallest depth of a node that can be visited from the subtree of x
    int n;cin>>n;
    for(int i=1;i<n;i++){
        int x,y; cin>>x>>y;
        gr[x].push_back(y);
        gr[y].push_back(x);
    }
    dfs(1,1,0);
    for(int i=1;i<=n;i++){
        cout<<i<<" "<<dp[i]<<"\n";
    }
    return 0;
}