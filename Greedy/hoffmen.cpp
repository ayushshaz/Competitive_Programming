#include<bits/stdc++.h>
namespace {
using namespace std;

#define F first
#define S second
#define pb push_back
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define rrep(i,n) for(int i = (int)(n) - 1; i >= 0; i--)
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
template<class T> bool chmax(T& a, const T& b) { if (a < b) { a = b; return true; } else return false; }
template<class T> bool chmin(T& a, const T& b) { if (b < a) { a = b; return true; } else return false; }
using ll = long long;
using P = pair<int,int>;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
}
struct node{
    char c;
    int f;
    node *left,*right;
    node(char c, int f, node *a, node *b){
        this->c=c;
        this->f=f;
        left=a;
        right=b;
    }
};

class arrange{
    public:
    bool operator()(node a, node b){
        if(a.f>b.f){
            return true;
        }
        return false;
    }
};
void output_tree(node *tree, vector<bool> b){
    if(tree->c != ' '){ //or (tree->left==NULL && tree->right==NULL) same thing
        cout<<tree->c<<" "<<tree->f<<" "<<b.size();
        // for(auto x : b){
        //     cout<<x<<" ";
        // }
        // cout<<endl;
        return;
    }
    b.push_back(0);
    output_tree(tree->left,b);
    b.pop_back();
    b.push_back(1);
    output_tree(tree->right,b);
    b.pop_back();
}

void print_the_tree(node tree){
   vector<bool> b;
   output_tree(&tree,b);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  priority_queue<node,vector<node>,arrange>  pq;
  int n; cin>>n;
  while(n--){
     char c; int w; cin>>c>>w;
     pq.push(node(c,w,NULL,NULL));
  }
  while(pq.size()!=1 && pq.size()>=1){
    node first = pq.top(); pq.pop();
    node second = pq.top(); pq.pop();
    node merge = node(' ',first.f+second.f,&first,&second);
    pq.push(merge);
  }
  print_the_tree(pq.top());
}