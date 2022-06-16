#include<bits/stdc++.h>
// #include <boost/range/adaptor/reversed.hpp>  auto x: reverse(segment_ans)
using namespace std; 

template <typename T>
class Graph{
    map<T, list<T>> l;
    map<T,bool> visited;
    list<T> ans, segment_ans;
public:
    void addEdge(T x,T y){
        l[x].push_back(y);  
    }

    void bfs(T v){
        queue<T> q;
        q.push(v);
        
        while(!q.empty()){
            T curr = q.front();
            segment_ans.push_back(curr);
            q.pop();
            visited[curr]= true;
            // cout<<curr<<" ";
            for(auto nbr: l[curr]){
                if(!visited[nbr]){
                    q.push(nbr);
                }
            }
        }
        // cout<<v<<"=>";
        // for(auto x:segment_ans){
        //     cout<<x<<" ";
        // }
        // cout<<endl;
    }
    void bfs_topo(){
        for(auto vertex: l){
            if(!visited[vertex.first]){
                bfs(vertex.first);
                for(auto i = segment_ans.rbegin();i!=segment_ans.rend();i++){   
                    ans.push_front(*i);
                }
                segment_ans.clear();
            }
        }
        for(auto z: ans){
            cout<<z<<" ";
        }
    }
};

int main(){
    Graph<string> g;
    g.addEdge("Python","DataPreprocessing");
    g.addEdge("Python","PyTorch");
    g.addEdge("Python","ML");
    g.addEdge("DataPreprocessing","ML");
    g.addEdge("PyTorch","DL");
    g.addEdge("ML","DL");
    g.addEdge("DL","FaceRecognition");
    g.addEdge("Dataset","FaceRecognition");
    g.bfs_topo();

    return 0;
}