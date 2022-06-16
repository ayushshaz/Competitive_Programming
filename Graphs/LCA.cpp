#include<bits/stdc++.h>
using namespace std;

const int N = 100005;
vector<int> gr[N];
int par[N],dep[N];
bool visited[N];

vector<vector<int>> mat(N,vector<int>(23));

void build_sparse(int n){
    for(int i=1;i<=n;i++){
        mat[i][0]=par[i];
    }
    for(int j=1;j<=log2(n);j++){
        for(int i=1;i<=n;i++){
            mat[i][j] = mat[mat[i][j-1]][j-1];  // will store parent
        
        }
    }
    // for(int i=1;i<=n;i++){
    //     cout<<i<<" ";
    //     for(int j=0;j<=log2(n);j++){
    //         cout<<mat[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
}

int lca_logn(int l,int r){
    if(l==r) return l;
    if(dep[l]<dep[r]) swap(l,r); // l will always be greater
    
    int depth = dep[l]-dep[r];
    int pow =0;
    while(depth>0){
        if(depth&(1<<pow)){
            l=mat[l][pow];
            depth=depth-(1<<pow);
        }
        pow++;
    } 
    // now both are same level
    if(l==r){
        return l;
    }
    pow=0;
    int top_l, top_r;
    while(!(l!=r && par[l]==par[r])){   // ideal condition where we have our lca, loop will run till that is reached 
        top_l = mat[l][1<<pow];
        top_r = mat[r][1<<pow];
        if(top_l==top_r){
            pow=0;
            continue;
        }
        if(top_l!=top_r){
            l=top_l;
            r=top_r;      
        }
        pow++;
    }
    return par[l];
}

int lca_n(int l, int r){
    if(l==r) return l;
    if(dep[l]<dep[r]) swap(l,r); // l will always be greater

    while(dep[l]-dep[r]>0){
        l=par[l];
    }   
    // now both are at same level
    while(l!=r){
        l=par[l];
        r=par[r];
    }
    return l;
}

void dfs(int v,int p,int d){
    visited[v]=true;
    par[v]=p; dep[v]=d;
    for(auto nbr:gr[v]){
        if(!visited[nbr]){
            dfs(nbr,v,d+1);       
        }
    }   
}

int main(){         
    int v,n;cin>>v>>n;
   while(n--){
        int x,y; cin>>x>>y;
        gr[x].push_back(y);
        gr[y].push_back(x);
    }
    dfs(1,1,0); // parent and depth stored
    // cout<<lca_n(16,13)<<endl;
    build_sparse(v);
    cout<<lca_logn(16,19)<<" ";
    cout<<lca_n(16,19);
    return 0;
}


