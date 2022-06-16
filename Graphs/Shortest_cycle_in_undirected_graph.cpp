#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define pb push_back
#define P pair<int, int>

const int N = 100005, M=22;

vector<int> graph[N];

void bfs(int v,int n,int &ans){
    vector<int> dist(n+1,INT_MAX);
    queue<int> q;
    // map<int,bool> visited;
    q.push(v);
    dist[v]=0;
    while (!q.empty())
    {
        int curr = q.front();
        // visited[curr]=true;
        q.pop();
        for(auto nbr:graph[v]){
            if(dist[nbr]==INT_MAX){          // !visited[nbr]
                q.push(nbr);
                dist[nbr] = dist[v]+1;
            }else if(dist[nbr]>=dist[curr]){ //  not a parent in the best case.
                ans=min(ans,dist[nbr]+dist[curr]+1);
            }
        }   
    }
}

void solve(){
	int k,n,m,ans=n+1,cnt=0,sum=0;	
    cin>>m>>n;
    for (int i = 0; i < n; i++)
    {
        int x,y; cin>>x>>y;
        graph[x].pb(y);
        graph[y].pb(x);
    }
    for(int i=1;i<=m;i++){
        bfs(i,m,ans);   // 1 to n vertex
    }    
    if(ans==n+1){
        cout<<"No Cycle Detected"<<"\n";
    }else{
        cout<<"The shortest cycle length is "<<ans<<endl;
    }
}

void init(){
	ios_base:: sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
#ifndef ONLINE_JUDGE 
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif	
}
	
int32_t main(){
	// init();
	int t;cin>>t;while(t--){
		solve();
	}
	return 0;
}

// 1
// 5 6
// 1 2
// 1 3
// 2 4
// 2 5
// 4 5
// 5 3 
// Output 3.

//Logic through DFS fails in some cases when short cycle is getting formed while touching first cycle.

// #include<bits/stdc++.h>
// using namespace std;

// template <typename T>
// class Graph{
//     map<T, list<T>> l;
//     map<T,bool> visited;
//     map<T,T> parent;
//     map<T,int> depth;
// public:
//     int ans=INT_MAX; // ans has shortest cycle

//     void addEdge(T x,T y){
//         l[y].push_back(x);
//         l[x].push_back(y);
//     }

//     bool cycle_detection(T v,int deep){
//         depth[v] = deep;
//         visited[v]=true;
//         for(auto nbr: l[v]){
//             if(visited[nbr]&& parent[v]!=nbr){  //cycle detected
//                 ans= min(ans,depth[v]-depth[nbr]+1);
//                 return true;
//             }
//             if(!visited[nbr]){
//                 parent[nbr] = v;
//                 return cycle_detection(nbr,deep+1);
//             }
//         }
//         return false;
//     }
// };

// int main(){
//     Graph<int> g;
//     g.addEdge(0,1);
//     g.addEdge(1,2);
//     g.addEdge(2,3);
//     g.addEdge(3,4);
//     g.addEdge(4,1);
//     g.addEdge(4,0);

//     if(g.cycle_detection(0,0)){
//         cout<<"Cycle Detected and its length is "<<g.ans<<" \n";
//     }else{
//         cout<<"No Cycle Detected"<<"\n";
//     }
//     return 0;
// }