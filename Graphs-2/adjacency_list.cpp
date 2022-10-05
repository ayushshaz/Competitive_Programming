#include<iostream>
#include<list>
using namespace std;

class Graph{
    int V;
    list<int> *l;
public:
    Graph(int V){
        this->V= V;
        l = new list<int>[V];
    }

    void Edge(int u,int v){
        l[u].push_back(v);
        l[v].push_back(u);
    }
    void PrintList(){
        for(int i=0;i<V;i++){
            cout<<"Vertex "<<i<<"->";
            for(int nbr : l[i]){
                cout<<nbr<<",";
            }
            cout<<"\n";
        }

    }
};

int main(){
    Graph g(4);
    g.Edge(0,1);
    g.Edge(0,2);
    g.Edge(2,3);
    g.Edge(1,2);
    g.PrintList();

    return 0;
}