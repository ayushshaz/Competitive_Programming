#include <bits/stdc++.h> // Heap is of structure itself so data is getting lost and different data gets allocated at runtime at same memory location in next iteration of the loop
using namespace std;
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
    bool operator()(node l,node r){
        return l.freq > r.freq;
    }
};
node* newnode(char c, int d){
    node* n= new node(c,d);
    return n;
}
void print_first(node first){
    cout<<"First queue "<<first.data<<" "<<first.freq<<" "<<first.l<<" "<<first.r<<endl;
    if(first.l!=NULL){
        cout<<"Its left and right char "<<first.l->data<<" "<<first.l->freq<<" "<<first.r->data<<" "<<first.r->freq<<endl;
    }
}
void print_last(node *merge){
    cout<<" Merging "<<merge->l->data<<" "<<merge->l->freq<<" "<<merge->r->data<<" "<<merge->r->freq<<"\n "<<merge->data<<" "<<merge->freq<<" "<<merge->l<<" "<<merge->r<<endl;
    cout<<"End of loop"<<endl;
}
int main() {
    priority_queue<node,vector<node>,comp> map;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        char c; int d;
        cin>>c>>d;
        node* e=newnode(c,d);
        map.push(*e);
    }
    while(map.size()!=1){
        node first =map.top();
        map.pop();
        print_first(first);
        node second =map.top();
        map.pop();
        node* merge=newnode(' ',first.freq+second.freq);
        merge->l=&first;
        merge->r=&second;
        map.push(*merge);
        print_last(merge);
    }
    return 0;
}