#include<bits/stdc++.h>
using namespace std;

template <typename T>
class Graph{
    map<T, list<T>> l;
    map<T,bool> visited;
public:
    void addEdge(T x,T y){
        l[y].push_back(x);
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
    }
    int connected_components(){
        int count = 0;
        for(auto x: l){
            if(!visited[x.first]){
                dfs(x.first);
                count++;
            }
        }
        return count;
    }
};

int main(){
    Graph<int> g;
    g.addEdge(0,1);
    g.addEdge(0,4);
    g.addEdge(0,3);
    g.addEdge(1,2);
    g.addEdge(2,3);

    g.addEdge(5,6);
    g.addEdge(6,7);

    g.addEdge(8,8);    // required for 8 to exist in map  as a vertex.  

    cout<<g.connected_components();

    return 0;
}