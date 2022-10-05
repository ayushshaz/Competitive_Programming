#include<bits/stdc++.h>
using namespace std;

list<pair<int,int>> edges;

void addEdge(int v,int u){
    edges.push_back(make_pair(v,u));
}

int findSet(int x,int parent[]){
    if(parent[x]==-1){
        return x;
    }
    return findSet(parent[x],parent);
}

void UnionSet(int x,int y,int parent[]){
    int u = findSet(x,parent);
    int v = findSet(y,parent);
    if(u!=v){
        parent[v]=u;
    }
} 

bool containsCycle(int vertex){
    int *parent = new int[vertex];
    memset(parent,-1,sizeof(parent));
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