#include<bits/stdc++.h>
namespace {
using namespace std;


#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define rrep(i,n) for(int i = (int)(n) - 1; i >= 0; i--)
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
template<class T> bool chmax(T& a, const T& b) { if (a < b) { a = b; return true; } else return false; }
template<class T> bool chmin(T& a, const T& b) { if (b < a) { a = b; return true; } else return false; }
using ll = long long;
using P = pair<int,int>;
using VI = vector<int>;
using VVI = vector<VI>;
using VL = vector<ll>;
using VVL = vector<VL>;
} 

VVI multiply_matrix(VVI a, VVI b){
  VVI ans(a.size(),VI(a.size(),0));
  for(int i=0;i<a.size();i++){
    for(int j=0;j<a.size();j++){
      for(int k=0;k<a.size();k++){
        ans[i][j] += a[i][k]*b[k][j]; 
      }
    }
  }
  return ans;
}

VVI matrix_power(VVI mat, int p){
  VVI ans(mat.size(),VI(mat.size()));
  for(int i=0;i<mat.size();i++){
    ans[i][i]=1; // make it equal to identity
  }
  while(p>0){
    if(p&1){
      ans = multiply_matrix(ans,mat);
    }
    mat = multiply_matrix(mat,mat);
    p = p/2;
  }
  return ans;
}

void print_vector(VVI ans){
  for(int i=0;i<ans.size();i++){
    for(int j=0;j<ans.size();j++){
      cout<<ans[i][j]<<" ";
    }
    cout<<"\n";
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--){
    int p; cin>>p;
    int n,m; cin>>n>>m; // enter n and m as same for matrix multiplication
    VVI mat(n,VI(m));
    for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
        cin>>mat[i][j];
      }
    }
    VVI ans = matrix_power(mat,p);   
    print_vector(ans);
  }
}