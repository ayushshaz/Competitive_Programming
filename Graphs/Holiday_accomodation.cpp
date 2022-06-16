#include<bits/stdc++.h>
using namespace std;

map<int,list<pair<int,int>>> g;
void addEdge(int u,int v,int w){
    g[u].push_back(make_pair(v,w));
    g[v].push_back(make_pair(u,w));

}
map<int,bool> visited;
int visits;

void dfs(int v){
    visited[v]=true;
    visits++;
    for(auto x:g[v]){
        if(!visited[x.first]){
            dfs(x.first);
        }
    }
}

int solve(){
    int ans;
    for(auto x:g){
        int node = x.first;
        if(g[node].size()>1){ // side node not required

        }
    }
    return ans;
}

int main(){
    int t;cin>>t;
    int i=1;
    while(t--){
        int x;cin>>x;x--;
        while(x--){
            int u,v,w; cin>>u>>v>>w;
            addEdge(u,v,w);
        }
        int result = solve();
        cout<<"Case #"<<i<<": "<<result<<"\n";i++;
        g.clear();
        visited.clear();
    }
    return 0;
}