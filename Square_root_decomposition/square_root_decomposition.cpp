#include<bits/stdc++.h>
using namespace std;

int range(int l,int r,int *arr, int *block,int n){  // range in 3 times root n times 
    int rn = sqrt(n);
    int ans=0;
    for(int i=l;i<=r;){
        
        if(i%rn==0){
            ans+=block[i/rn];
            i=i+rn;
        }else{
            ans+=arr[i++];
        }
    }
    return ans;
}
void update(int i,int u,int *arr,int *block,int n){   // updated in const time
    int rn = sqrt(n);
    block[i/rn] = block[i/rn] - arr[i] + u;
    arr[i]=u;
}
int main(){
    int arr[] = {1,3,5,2,7,6,3,1,4,8};
    int n= sizeof(arr)/sizeof(arr[0]);

    int block[n]={0};
    int rn=sqrt(n);

    for(int i=0;i<n;i++){
        block[(i/rn)]+=arr[i];
    }   // block is ready
    update(2,7,arr,block,n);// update index 2 with 7
    cout<<range(2,8,arr,block,n);

    return 0;
}