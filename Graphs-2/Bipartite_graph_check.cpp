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

    bool bipartite_detect(T v,int count){ // check for odd length cycle if exist then false else true.
        visited[v]=true;
        for(auto nbr: l[v]){
            if(visited[nbr]&& parent[v]!=nbr && count%2 == 1){
                return false;
            }
            if(!visited[nbr]){
                parent[nbr] = v;
                return bipartite_detect(nbr,count+1);
            }
        }
        return true;
    }
    bool bipartite_detect_check(int v){
        bool ans = true; 
        for(auto x: l){
            if(!visited[x.first]){
                ans = ans && bipartite_detect(x.first,1);
            }
        }
        return ans;
    }

};

int main(){
    Graph<int> g;
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.addEdge(4,0);
    
    if(g.bipartite_detect_check(0)){
        cout<<"The Graph is Bipartite"<<"\n";
    }else{
        cout<<"The Graph is not Bipartite"<<"\n";
    }
    return 0;
}