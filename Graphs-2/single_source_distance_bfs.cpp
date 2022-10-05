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

    void bfs_dist(T v){ //other way is to keep dist[]=INT_MAX and compare if dist[i]==INTMAX this would be more faster as O(1).
        map<T,int> dist;
        queue<T> q;
        q.push(v);
        dist[v]=0;

        while(!q.empty()){
            T curr = q.front();
            q.pop();
            // cout<<curr<<" ";
            for(auto nbr: l[curr]){
                if(dist.find(nbr)==dist.end()){
                    q.push(nbr);
                    dist[nbr]=dist[curr]+1;
                }
            }
        }
        for(auto x: dist){
            cout<<x.first<<" "<<x.second<<"\n";
        }
    }
    void bfs_dist_faster(T v){ 
        queue<T> q;
        map<T,int> distance;
        q.push(v);
        for(auto x:l){
            distance[x.first]=INT_MAX;
        }
        distance[v]=0;

        while(!q.empty()){
            T curr = q.front();
            q.pop();
            // cout<<curr<<" ";
            for(auto nbr: l[curr]){
                if(distance[nbr]==INT_MAX){
                    q.push(nbr);
                    distance[nbr]=distance[curr]+1;
                }
            }
        }
        for(auto x: distance){
            cout<<x.first<<" "<<x.second<<"\n";
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
    g.bfs_dist_faster(0);
    return 0;
}