#include<bits/stdc++.h>
using namespace std;

template <typename T>
class Graph{
    map<T, list<T>> l;
    map<T,bool> visited;
    map<T,T> parent;
public:
    void addEdge(T x,T y){
        l[y].push_back(x);
        l[x].push_back(y);
    }

    bool cycle_detection(T v){
        visited[v]=true;
        for(auto nbr: l[v]){
            if(visited[nbr]&& parent[v]!=nbr){
                return true;
            }
            if(!visited[nbr]){
                parent[nbr] = v;
                return cycle_detection(nbr);
            }
        }
        return false;
    }
};

int main(){
    Graph<int> g;
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.addEdge(4,5);
    if(g.cycle_detection(0)){
        cout<<"Cycle Detected"<<"\n";
    }else{
        cout<<"No Cycle Detected"<<"\n";
    }
    return 0;
}