#include<bits/stdc++.h>
using namespace std;

int maxSubarraySum(int arr[], int n){
    
    int maxsum=0,sum=0;
    
    for(int i=0;i<n;i++){
        sum+=arr[i];
        if(sum>0){
            maxsum=max(maxsum,sum);
        }else{
            sum=0;
        }
    }
    return maxsum;
}

int main(){
    int arr[] = {-3,2,5,-1,6,3,-2,7,-5,2};
    cout<<maxSubarraySum(arr,10);
    return 0;
}