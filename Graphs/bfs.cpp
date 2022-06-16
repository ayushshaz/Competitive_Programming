#include<bits/stdc++.h>
using namespace std;

template <typename T>
class Graph{
    map<T, list<T>> l;
public:
    void addEdge(T x,T y){
        l[y].push_back(x);
        l[x].push_back(y);
    }

    void bfs(T v){
        map<T,bool> visited;
        queue<T> q;
        q.push(v);
        while(!q.empty()){
            T curr = q.front();
            q.pop();
            visited[curr]= true;
            cout<<curr<<" ";
            for(auto nbr: l[curr]){
                if(!visited[nbr]){
                    q.push(nbr);
                }
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
    g.bfs(0);

    return 0;
}