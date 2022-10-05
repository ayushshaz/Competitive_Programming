#include<bits/stdc++.h>
using namespace std;
const int N=100005;

vector<int> graph[N],rev_graph[N];
stack<int> finished;

void dfs(int v,map<int,bool> &visited,vector<int> graph[]){
    visited[v]=true;
    for(auto nbr:graph[v]){
        if(!visited[nbr]){
            dfs(nbr,visited,graph);
        }
    }
    finished.push(v);
}

int main(){
    map<int,bool> visited;
    int v,e;cin>>v>>e;
    for(int i=0;i<e;i++){
        int x,y;cin>>x>>y;
        graph[x].push_back(y);
        rev_graph[y].push_back(x);
    }
    dfs(0,visited,graph);
    
    int comp=0; visited.clear();
    
    while(!finished.empty()){
        int top = finished.top();
        finished.pop();
        if(!visited[top]){
            dfs(top,visited,rev_graph);
            comp++;
        }
    }
    cout<<"The number of component are "<<comp<<"\n";
    return 0;
}