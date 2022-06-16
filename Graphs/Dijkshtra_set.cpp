#include<bits/stdc++.h>
using namespace std;

map<int,list<pair<int,int>>> gr;    // u->v weight
map<int,int> dist;                  // vertex distance : required for erasing from set
map<int,bool> visited;

class comparator{
    public:
    bool operator()(pair<int,int> a, pair<int,int> b){
        return a.second < b.second;
    }
};

multiset<pair<int,int>, comparator> s; // vertex, distance

void dijkshtra(int vertex, int n){
    s.erase(make_pair(vertex,dist[vertex]));
    dist[vertex]=0;
    
    for(int i=1;i<n;i++){                                   // take out the remaining n-1 nodes
        visited[vertex]=true;
        for(auto x: gr[vertex]){
            if(dist[vertex]==INT_MAX){                   // selected vertex is not reachable from the start
                s.erase(make_pair(vertex,dist[vertex]));
                break;
            }
            if(dist[vertex]+x.second<dist[x.first] && !visited[x.first]){
                s.erase(make_pair(x.first,dist[x.first]));
                dist[x.first] = dist[vertex] + x.second;
                s.insert(make_pair(x.first,dist[x.first]));
            }
            if(vertex==1){
                for(auto y:s){
                    cout<<y.first<<" "<<y.second<<endl;
                }
            }
        }
        vertex = (*s.begin()).first;
        // cout<<vertex<<" "<<dist[vertex]<<" "<<endl;
        s.erase(s.begin());
    } 
    for(int i=1;i<=n;i++){
        cout<<"Distance to vertex "<<i<<" is "<<dist[i]<<"\n"; 
    }
}

int main(){
    int v,e; cin>>v>>e;
    while(e--){
        int x,y,z;cin>>x>>y>>z;
        gr[x].push_back(make_pair(y,z));
        gr[y].push_back(make_pair(x,z));
    }
    for(int i=0;i<=v;i++){
        dist[i]=INT_MAX;
    }
    for(int i=1;i<=v;i++){
        s.insert(make_pair(i,dist[i]));
    }
    dijkshtra(1,v);
    return 0;
}   


// Test case
// 9 14
// 1 2 4
// 1 8 8
// 2 8 11
// 8 9 7
// 3 9 2
// 9 7 6
// 7 8 1
// 6 7 2
// 4 6 14
// 4 5 9
// 5 6 10
// 3 4 7
// 2 3 8
// 3 6 4