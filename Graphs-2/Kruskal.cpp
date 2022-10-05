#include<bits/stdc++.h>
using namespace std;
struct Edge
{
    int f,s,w;
};
vector<Edge> Edges;
vector<int> parent;
map<int,int> ranks;

bool compareEdge(Edge a,Edge b){
    return a.w < b.w;
}
int find_parent(int v){
    return v == parent[v]? v : parent[v]=find_parent(parent[v]); 
}

bool union_all_cycle_found(int f,int s){
    int first = find_parent(f);
    int second = find_parent(s);
    if(first==second){
        return true;
    }
    if(ranks[first]>ranks[second]){
        parent[second]=first;
        ranks[first] = ranks[first]+ranks[second];
    }else{
        parent[first]=second;
        ranks[second] = ranks[first]+ranks[second];
    }
    return false;
}

int main(){
    int n,v;cin>>n>>v;
    while(n--){
        int x,y,w; cin>>x>>y>>w;
        Edge e; e.f=x; e.s=y, e.w=w;
        Edges.push_back(e);      
    }
    sort(Edges.begin(), Edges.end(), compareEdge);
    parent.resize(v+1);
    iota(parent.begin(),parent.end(),0);
    for(auto e:Edges){
        if(union_all_cycle_found(e.f,e.s)){
            continue;
        }
        cout<<"The edges included in spamming tree are :"<<e.f<<" "<<e.s<<" "<<" with weight "<<e.w<<"\n";
    }
    return 0;
}