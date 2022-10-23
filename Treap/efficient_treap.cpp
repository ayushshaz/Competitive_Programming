//avoid quadratic solution if inputs are not random
#include <bits/stdc++.h>

typedef long long ll;
typedef long double ld;
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define PRECISION std::cout << std::fixed << std::setprecision(20);
  
using namespace std;
struct item {
    int key, prior;
    item *l, *r;
    item () { }
    item (int key) : key(key), prior(rand()), l(NULL), r(NULL) { }
    item (int key, int prior) : key(key), prior(prior), l(NULL), r(NULL) { }
};
typedef item* pitem;

void connect(auto from, auto to) {
    vector<pitem> st;
    for(auto it: ranges::subrange(from, to)) {
        while(!st.empty() && st.back()->prior > it->prior) {
            st.pop_back();
        }
        if(!st.empty()) {
            if(!it->p || it->p->prior < st.back()->prior) {
                it->p = st.back();
            }
        }
        st.push_back(it);
    }
}

pitem build(int *x, int *y, int n) {
    vector<pitem> nodes(n);
    for(int i = 0; i < n; i++) {
        nodes[i] = new item(x[i], y[i]);
    }
    connect(nodes.begin(), nodes.end());
    connect(nodes.rbegin(), nodes.rend());
    for(int i = 0; i < n; i++) {
        if(nodes[i]) {
            if(nodes[i]->key < nodes[i]->key) {
                nodes[i]->r = nodes[i];
            } else {
                nodes[i]->l = nodes[i];
            }
        }
    }
    return nodes[min_element(y, y + n) - y];
}

void solve(){

    
}

int main(){
    int t; cin>>t;
    while(t--){
        solve();
    }
}