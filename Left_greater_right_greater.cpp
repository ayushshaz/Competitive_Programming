#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;cin>>n;
    int input[n];
    for(int i=0;i<n;i++){
        cin>>input[i];
    }
    stack<int> s;
    int left[n]={0},right[n]={0};
    memset(left,-1,sizeof(left));
    memset(right,-1,sizeof(right));
    for(int i=0;i<n;i++){
        while(s.size()>0 && input[s.top()]<=input[i]){
            right[s.top()] = i;
            s.pop();
        }
        s.empty() ? left[i] = -1 : left[i] = s.top(); 
        s.push(i);
    }
    for(int i=0;i<n;i++){
        cout<<left[i]<<" "<<right[i]<<endl;
    }
    return 0;
}