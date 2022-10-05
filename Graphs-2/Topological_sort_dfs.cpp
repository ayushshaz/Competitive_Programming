#include<bits/stdc++.h>
using namespace std; 

template <typename T>
class Graph{
    map<T, list<T>> l;
    map<T,bool> visited;
    list<T> ans;
public:
    void addEdge(T x,T y){
        l[x].push_back(y);  
    }

    void dfs(T v){
        visited[v]=true;
        // cout<<v<<" ";
        for(auto nbr: l[v]){
            if(!visited[nbr]){
                dfs(nbr);
            }
        }
        ans.push_front(v);
    }
    void dfs_topo(){
        for(auto vertex: l){
            if(!visited[vertex.first]){
                dfs(vertex.first);
            }
        }
        for(auto z: ans){
            cout<<z<<" ";
        }
    }
};

int main(){
    Graph<string> g;
    g.addEdge("Python","DataPreprocessing");
    g.addEdge("Python","PyTorch");
    g.addEdge("Python","ML");
    g.addEdge("DataPreprocessing","ML");
    g.addEdge("PyTorch","DL");
    g.addEdge("ML","DL");
    g.addEdge("DL","FaceRecognition");
    g.addEdge("Dataset","FaceRecognition");
    g.dfs_topo();

    return 0;
}