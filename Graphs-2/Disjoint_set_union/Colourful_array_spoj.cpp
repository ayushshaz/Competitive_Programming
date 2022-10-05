#include<bits/stdc++.h>
using namespace std;

long long int ans[200001];

class comparator{
public:
    bool operator()(pair<pair<int,int>,pair<long long int,int>> a,pair<pair<int,int>,pair<long long int,int>> b){
        return a.second.second < b.second.second;
    }
};

priority_queue< pair<pair<int,int>,pair<long long int,int>>, vector<pair<pair<int,int>,pair<long long int,int>>>, comparator> pq;
map<int,list<pair<int,int>> > input;
map<pair<int,int>,long long int> color;
pair<pair<int,int>,pair<long long int,int>> onTop; 
int main(){
    int n,q; cin>>n>>q;
    int rank=0;
    while(q--){
        int l,r,c; cin>>l>>r>>c;rank++;
        color[make_pair(l,r)] = c;
        input[l].push_back(make_pair(r-l+1,rank));
        // pq.push(make_pair(make_pair(l,r-l+1),make_pair(c,rank)));
    }
    for(int i=1;i<=n;i++){
     if(input[i].size()>0){ //push values into queue
        for(auto all:input[i]){
            pq.push(make_pair(make_pair(i,all.first),make_pair(color[make_pair(i,all.first-1+i)],all.second)));
            // l,shift,value,rank
        }
     }
     if(i>onTop.first.first+onTop.first.second-1 || i==1){
        //  onTop.first.first=0;    this doesn't work
        //  onTop.first.second=0;
        //  onTop.second.first=0;
        //  onTop.first.second=0;
        onTop = {{0,0},{0,0}};
     }
     //choose top from there and should be of the range
     while(!pq.empty()){
         //rank greater and i < l+shift-1
         if(onTop.second.second<pq.top().second.second && i<=pq.top().first.first+pq.top().first.second-1){
            //  if top range not finished insert back
             if(onTop.second.second > 0 && i+1 <= onTop.first.first + onTop.first.second-1){
                 pq.push(onTop);
             }
              onTop= pq.top();
              pq.pop();
              break;
         }else if(i>pq.top().first.first+pq.top().first.second-1){
             pq.pop();
         }else{
             break;
         }
     }
     //i<l+shift-1 and rank>0 it should not be empty 
     if(i <= onTop.first.first + onTop.first.second-1 && onTop.second.second>0){
         ans[i] = onTop.second.first; 
     }
    }
    for(int i=1;i<=n;i++){
        cout<<ans[i]<<"\n";
    }
    return 0;
}