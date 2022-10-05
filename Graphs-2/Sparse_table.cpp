#include<bits/stdc++.h>
using namespace std;

struct sparse_table{
    vector<vector<int>> mat;
    int n,m;
    vector<int> p2;
    
    void init(int _n, int _m){
        n=_n;
        m=_m;
        mat.resize(n);
        for(int i=0;i<n;i++){
            mat[i].resize(m);
        }
        p2.resize(n+1);
        for(int i=2;i<=n;i++){
            p2[i]=p2[i/2]+1;   // stores log2 value till n 
        }
    }
    void build(int arr[]){
        for(int i=0;i<n;i++){
            mat[i][0]=arr[i];
        }
        for(int i=0;i<n;i++){
            for(int j=1; i+(1<<j)-1 < n; j++){
                mat[i][j] = min(mat[i][j-1],mat[i+(1<<(j-1))][j-1]);
            }
        }
    }
    
    int query(int l,int r){
        int pw = p2[r-l];
        return min(mat[l][pw],mat[r-(1<<pw)+1][pw]);
    }

    void build_sum(int arr[]){
        for(int i=0;i<n;i++){
            mat[i][0]=arr[i];
        }
        for(int j=1;j<m;j++){
            for(int i=0; i+(1<<j)-1 < n; i++){
                mat[i][j] = mat[i][j-1]+mat[i+(1<<(j-1))][j-1];
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cout<<mat[i][j]<<" ";
            }
            cout<<endl;
        }
    }

    int query_general(int l,int r){    // general query get the answer from every box
        int index = l;
        int pRange = p2[r-l+1];
        int ans = 0;
        while(index<=r){
             ans = ans+mat[index][pRange];
             index=index+(1<<pRange);
             pRange = p2[r-index+1];
        }
        return ans;
    }
};

int main(){
    int n;cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sparse_table s;
    s.init(10,4);
    s.build_sum(arr);
    cout<<s.query_general(0,9); 
    return 0;
}