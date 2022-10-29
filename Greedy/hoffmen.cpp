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
class node{
    public:
    char data;
    int freq;
    node* l;
    node* r;
    node(char d,int f){
        data=d;
        freq=f;
        l=NULL;
        r=NULL;
    }
};
class comp{
    public:
    bool operator()(node* l,node* r){
        return l->freq > r->freq;
    }
};
node* newnode(char c, int d){
    node* n= new node(c,d);
    return n;
}
void encodingTree(node *tree,string &code){
    if(tree==NULL){
        return;
    }
    if(tree->data!=' '){
        cout<<tree->data<<" "<<code<<"\n";
        return;
    }
    code.push_back('0');
    encodingTree(tree->l,code);
    code.pop_back();
    code.push_back('1');
    encodingTree(tree->r,code);
    code.pop_back();
}

int main() {
    priority_queue<node*,vector<node*>,comp> map;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        char c; int d;
        cin>>c>>d;
        node* e=newnode(c,d);
        map.push(e);
    }
    while(map.size()!=1){
        node* first =map.top();
        map.pop();
        node* second =map.top();
        map.pop();
        node* e=newnode(' ',first->freq+second->freq);
        e->l=first;
        e->r=second;
        map.push(e);
    }
    string code="";
    encodingTree(map.top(),code);
    return 0;
}