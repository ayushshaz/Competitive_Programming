#include<bits/stdc++.h>
using namespace std;

struct Point{
    int x,y;
    bool operator < (Point &p){
        if(p.x==x){
            return p.y < y;
        }else{
            return p.x < x;
        }
    }
    bool operator == (Point &p){
        return x = p.x && y==p.y;
    }
};

bool ccw(Point a, Point b, Point c){
    return a.x*(b.y-c.y) + b.x*(c.y-a.y) + c.x*(a.y-b.y) < 0;
}

bool cw(Point a, Point b, Point c){
    return a.x*(b.y-c.y) + b.x*(c.y-a.y) + c.x*(a.y-b.y) > 0;
}

bool collinear(Point a, Point b, Point c){
    return a.x*(b.y-c.y) + b.x*(c.y-a.y) + c.x*(a.y-b.y) == 0;
}

void convex_hull(vector<Point> &p){
    if(p.size()<=2) return;
    sort(p.begin(), p.end()); 
    // first and last point are surely the points in hull
    Point n1 = p[0], n2 = p[p.size()-1];
    vector<Point> up, down;
    up.push_back(n1);
    down.push_back(n1);
    for(int i=1; i<p.size()-1; i++){
        if(i==p.size()-1 || !ccw(n1,p[i],n2)){
            //p[i] is in upper half
            while(up.size()>=2 || ccw(up[p.size()-2],up[p.size()-1],p[i])){
                up.pop_back();
            }
            up.push_back(p[i]);
        }
        if(i==p.size()-1 || !cw(n1,p[i],n2)){
            //p[i] is in lower half
            while(down.size()>=2 || cw(down[p.size()-2],down[p.size()-1],p[i])){
                down.pop_back();
            }
            down.push_back(p[i]);
        }
    }
    p.clear();
    for(int i=0;i<up.size();i++){
        p.push_back(up[i]);
    }
    for(int i=0;i<down.size();i++){
        p.push_back(down[i]);
    }
    sort(p.begin(),p.end());
    p.resize(unique(p.begin(),p.end())-p.begin());
}

int main(){
    int n;cin>>n;
    vector<Point> p(n);
    for(int i=0;i<n;i++){
        cin>>p[i].x>>p[i].y;
    }
    convex_hull(p);
    return 0;
}