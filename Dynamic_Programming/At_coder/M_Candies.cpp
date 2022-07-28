#include<bits/stdc++.h>
using namespace std;

int number_of_ways_candies(int arr[], int n, int k, int i){     // 'i' is an iterator to n
    // base case
    if(i==n-1){
        if(k>arr[i]){
            return 0;
        }
        return 1;
    }
    // // recursive case
    int ans=0;
    for(int j=0;j<=arr[i];j++){
        ans+=number_of_ways_candies(arr,n,k-j,i++);
    }
    return ans;
}

int main(){
    int n,k;cin>>n>>k;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<number_of_ways_candies(arr,n,k,0);
    return 0;
}