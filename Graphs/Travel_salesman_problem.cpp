#include<bits/stdc++.h>
using namespace std;
const int N = 10000;
int gr[N][N];
// vector<pair<int,int>> gr[N];    // we will have to iterate to find the edge weight
int dp[N];

int tsp(int mask, int curr, int v){
    if(dp[mask]!=-1){
        return dp[mask];
    }
    if(mask == (1<<v)-1){   // visited all 
        return gr[curr][0];
    }
    int ans=INT_MAX;
    for(int i=0;i<v;i++){
        if(!(mask&1<<i)){
            int newans = gr[curr][i]+tsp(mask+(1<<i),i,v);
            ans = min(ans, newans);
        }
    }
    return dp[mask]=ans;
}

int main(){
    int v,n;cin>>v>>n;
    while(n--){
        int x,y,w; cin>>x>>y>>w;
        // gr[x].push_back(make_pair(y,w));
        // gr[y].push_back(make_pair(x,w));
        gr[x][y]=w;
        gr[y][x]=w;
    }
    memset(dp,-1,sizeof(dp));
    cout<<tsp(1,0,v);
    return 0;
}