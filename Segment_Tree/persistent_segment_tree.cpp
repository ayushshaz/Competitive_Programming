#include<bits/stdc++.h>
using namespace std;

struct node{
    int value;
    node* left;
    node* right;
    node(){
        left=NULL;
        right=NULL;
        value=INT_MAX;
    }
};

class tree{
    public:
        node* root[100];    // k value can be till 100
        int update=0;

    void build_tree(int *arr, int s, int e, node* &root){
        root= new node();
        if(s==e){
            root->value = arr[s];
            return;
        }
        int mid = (s+e)/2;
        build_tree(arr,s,mid,root->left);
        build_tree(arr,mid+1,e,root->right);
        root->value = min(root->left->value,root->right->value);
    }

    void update_tree(int *arr, int s, int e, int index, int value, node* &root, node* previous){
        if(index<s || index>e){      // Out of bounds
            return;
        }
        root = new node();
        if(s==e){                    //Leaf node of our index
            root->value = value;
            // cout<<root->value<<endl;
            return;
        }
        int mid = (s+e)/2;
        update_tree(arr,s,mid,index,value,root->left,previous->left);
        update_tree(arr,mid+1,e,index,value,root->right,previous->right);

        if(index<s || index>mid){
            root->left = previous->left;
        }
        if(index<mid+1 || index>e){
            root->right = previous->right;
        }
        root->value = min(root->left->value,root->right->value);
        // cout<<root->value<<endl;
    }
    
    int kth_update_tree_value(int s, int e, int index, node* root){
        if(index<s || index>e){
            return INT_MAX;
        }
        if(index == s && index == e){
            return root->value;
        }
        int mid = (s+e)/2;
        return min(kth_update_tree_value(s,mid,index,root->left),
                   kth_update_tree_value(mid+1,e,index,root->right));
    }
};

int main(){
    int t;cin>>t;
    while(t--){
       int n,q; cin>>n>>q;
       int arr[n]; 
       for(int i=0;i<n;i++){
            cin>>arr[i];
       }
       tree s_tree;
       s_tree.build_tree(arr,0,n-1,s_tree.root[s_tree.update]);
       while(q--){
            int u,v; cin>>u>>v;
            s_tree.update++;
            s_tree.update_tree(arr,0,n-1,u,v,s_tree.root[s_tree.update],s_tree.root[s_tree.update-1]);  // u->index, v->value
       }
       int ver,index; cin>>ver>>index;
       cout<<s_tree.kth_update_tree_value(0,n-1,index,s_tree.root[ver]);
    }
    return 0;
}