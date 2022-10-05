#include<bits/stdc++.h>
using namespace std;

const int N = 10005;
vector<int> gr[N];
int lt[N],dt[N]; // lowest time, discovery time
bool visited[N];

void dfs(int v,int par, int t){
    int child=0;
    lt[v] = t;
    dt[v] = t;
    visited[v]=true;
    for(auto nbr: gr[v]){
        if(!visited[nbr]){
            child++;
            dfs(nbr,v,t+1);
            lt[v] = min(lt[v],lt[nbr]);
                
            if(v!=par && lt[nbr]>=dt[v]){                     //print the articulation point
                cout<<v<<" is Articulation Point\n";
            }
            if(lt[nbr]>dt[v]){                                //print the articulation bridge
                cout<<v<<"-"<<nbr<<" is Articulation Bridge\n";
            }
        }else if(nbr!=par){
            lt[v] = min(lt[v],dt[nbr]);
        }
    }
    if(v==par && child>1){   // separate case for root node if it has more than 1 child in dfs tree then its articulation point
        cout<<v<<" is Articulation Point\n";
    }
}

int main(){
    int n,e;cin>>n>>e;
    while(n--){
        int x,y; cin>>x>>y;
        gr[x].push_back(y);
        gr[y].push_back(x);
    }
    for(int i=0;i<N;i++){
        lt[i]=INT_MAX;
    }
    dfs(1,1,0);
    return 0;
}