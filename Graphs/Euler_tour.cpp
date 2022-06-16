#include<bits/stdc++.h>
using namespace std;

vector<int> gr[100005];
int tin[100005], tout[100005];
map<int,bool> visited;
int t;

void euler_tour_1(int n){ // 2*n-1  
    cout<<n;
    visited[n] = true;
    for(auto x: gr[n]){
        if(!visited[x]){
            euler_tour_1(x);
            cout<<n;     //for every edge
        }
    }
}

void euler_tour_2(int n){ //2n
    cout<<n;
    visited[n] = true;
    for(auto x: gr[n]){
        if(!visited[x]){
            euler_tour_2(x);
        }
    }
    cout<<n;
}

void euler_tour(int n){ // timee calculation
    tin[n] = ++t;
    visited[n] = true;
    for(auto x: gr[n]){
        if(!visited[x]){
            euler_tour(x);
        }
    }
    tout[n]=++t;
}
//is x is an ancestor of y
bool is_ancestor(int x,int y){
    return tin[x]<tin[y] && tout[x]>tout[y];
}

void euler_tour_flatten(int n){ // tree got flattened
    tin[n] = ++t;
    visited[n] = true;
    for(auto x: gr[n]){
        if(!visited[x]){
            euler_tour(x);
        }
    }
    tout[n]=t;  
}

int main(){
    int n;cin>>n;
    for(int i=1;i<n;i++){
        int x,y; cin>>x>>y;
        gr[x].push_back(y);
        gr[y].push_back(x);
    }
    euler_tour(1);
    for(int i=1;i<=n;i++){
        cout<<"vertex "<<i<<"-> Time in "<<tin[i]<<" Time out "<<tout[i]<<"\n";
    }
    if(is_ancestor(3,8)){
        cout<<"Yes\n";
    }else{
        cout<<"No\n";
    }
    return 0;
}