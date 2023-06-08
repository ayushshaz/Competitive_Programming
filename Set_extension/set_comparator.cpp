#include <bits/stdc++.h>
using namespace std;
class comparator{
  public:
    bool operator()(pair<int,int> a, pair<int,int> b){
        if(a.second<b.second){
            return true;
        }
        if(a.second==b.second){
            return a.first<b.first;
        }
        return false;
    }
};
bool compare(pair<int,int> a, pair<int,int> b){
    if(a.second<b.second){
        return true;   
    }
    if(a.second==b.second){
        return a.first<b.first;
    }
    return false;
}
int main(){
    set<pair<int,int>,comparator> s;
    s.insert(make_pair(1,5));
    s.insert(make_pair(2,4));
    s.insert(make_pair(3,4));
    s.insert(make_pair(2,5));
    s.insert(make_pair(4,2));
    s.insert(make_pair(5,1));
    for(auto x: s){
        cout<<x.first<<" "<<x.second<<endl;
    }
    cout<<endl;
    auto it  = upper_bound(s.begin(),s.end(),make_pair(2,4),compare);
    if(it!=s.end()){
        cout<<(*it).first<<" "<<(*it).second<<endl;
    }else{
        cout<<"Exited"<<endl;
    }
    return 0;
}