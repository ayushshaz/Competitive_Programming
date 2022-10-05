#include<bits/stdc++.h>
using namespace std;

class Graph{
    unordered_map<string,list<pair<string,int>>> l;
public:
    void addEdge(string x,string y, bool bidir,int wt){
        l[x].push_back(make_pair(y,wt));
        if(bidir){
            l[y].push_back(make_pair(x,wt));
        }
    }
    void PrintList(){
        for(auto x:l){
            cout<<x.first<<" ";
            for(auto nbr:x.second){
                cout<<nbr.first<<" "<<nbr.second<<" ";
            }
            cout<<"\n";
        }
    }
};

int main(){
    Graph g;
    g.addEdge("A","B",true,20);
    g.addEdge("B","D",true,40);
    g.addEdge("A","C",true,10);
    g.addEdge("C","D",true,40);
    g.addEdge("A","D",false,50);
    g.PrintList();
    return 0;
}