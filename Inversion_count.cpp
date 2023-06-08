#include <bits/stdc++.h>
using namespace std;

int get_inversions(int *arr, int left, int right){
    if(left>=right){
        return 0;
    }
    int mid=(left+right)/2;
    long long ans=0;
    ans+=get_inversions(arr,left,mid);
    ans+=get_inversions(arr,mid+1,right);
    // merge and count
    int a[right - left + 1] = {0};
    int i=left,j=mid+1,k=0;
    while(i<=mid && j<=right){
      if(arr[j]<arr[i]){
          ans+=(mid-i+1);
      }
      if(arr[i]<=arr[j]){
          a[k++]=arr[i++];
      }else{
          a[k++]=arr[j++];
      }
    }
    while(i<=mid){
        a[k++]=arr[i++];
    }
    while(j<=right){
        a[k++]=arr[j++];
    }
    // copy back the array
    for(int x=0;x<right-left+1;x++){
        arr[left+x]=a[x];
    }
    return ans;
}

int mergeSort(int arr[], int array_size)
{
	return get_inversions(arr, 0, array_size - 1);
}

int main()
{
	int arr[] = { 1, 20, 6, 4, 5 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int ans = mergeSort(arr, n);
	cout << " Number of inversions are " << ans;
	return 0;
}