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
    void bfs_dist(T v, T dest){ 
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
    int board[50] = {0};

    board[2]=13;
    board[5]=2;
    board[9]=18;
    board[18]=11;
    board[17]=-13;
    board[20]=-14;
    board[24]=-8;
    board[25]=10;
    board[32]=-2;
    board[34]=-22;

    Graph<int> g;
    for(int i=0;i<36;i++){
        for(int j=1;j<=6;j++){
            if(i,i+j+board[i+j] <= 36){
                g.addEdge(i,i+j+board[i+j]);    
            }
        }
    }
    
    g.bfs_dist(0,36);
    return 0;
}