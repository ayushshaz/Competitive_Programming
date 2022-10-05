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
        cout<<v<<" ";
        for(auto nbr: l[v]){
            if(!visited[nbr]){
                dfs(nbr);
            }
        }
    }
};

int main(){
    Graph<int> g;
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.addEdge(4,5);
    g.dfs(0);

    return 0;
}