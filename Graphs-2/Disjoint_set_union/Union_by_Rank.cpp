#include<bits/stdc++.h>
using namespace std;

list<pair<int,int>> edges;
map<int,int> ranked;

void addEdge(int v,int u){
    edges.push_back(make_pair(v,u));
}

int findSet(int x,int parent[]){
    if(parent[x]==-1){
        return x;
    }
    return parent[x] = findSet(parent[x],parent);   // path compression
}

void UnionSet(int x,int y,int parent[]){
    int u = findSet(x,parent);
    int v = findSet(y,parent);
    if(u!=v){
        if(ranked[v]>ranked[u]){
            parent[u]=v;
            ranked[v]+=ranked[u];
        }else{
            parent[v]=u;
            ranked[u]+=ranked[v];
        }
    }
} 

bool containsCycle(int vertex){
    int *parent = new int[vertex];
    memset(parent,-1,sizeof(parent));
    for(int i=0;i<=vertex;i++){
        ranked[i]=1;
    }
    for(auto e:edges){
        int u = findSet(e.first,parent);
        int v = findSet(e.second,parent);
        if(u!=v){
            UnionSet(u,v,parent);
        }else{
            return true;
        }
    }
    delete [] parent;
    return false;
}

int main(){
    addEdge(1,2);
    addEdge(2,3);
    addEdge(3,4);
    addEdge(4,1);
    if(containsCycle(5)){
        cout<<"Cycle Detected ";
    }else{
        cout<<"No Cycle Detected ";

    }
    return 0;
}