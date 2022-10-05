#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

void dfs(int src,map<int,bool> &visited,map<int, list<int>> &graph){
    visited[src]=true;
    for(auto nbr: graph[src]){
        if(!visited[nbr]){
            dfs(nbr, visited, graph);
        }
    }    
}
/*
 * Complete the 'journeyToMoon' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. 2D_INTEGER_ARRAY astronaut
 */

long long int journeyToMoon(int n, vector<vector<int>> astronaut) {
    map<int, list<int>> graph;
    map<int,bool> visited;
    for(int i=0;i<n;i++){ //vertex should exist
        graph[i].push_back(i);
    }
    for(auto x: astronaut){
        graph[x[0]].push_back(x[1]);
        graph[x[1]].push_back(x[0]);
    }
    long long int ans=0;
    for(auto x: graph){
        if(!visited[x.first]){
            int before = visited.size()-1;  //Checking in if visited size is increased
            // cout<<before<<" ";
            dfs(x.first,visited,graph);
            int count = visited.size()-before;
            // cout<<visited.size()<<endl;
            ans +=((long long int) (count))*(count-1)/2;  //nC2
        }
    }
    // cout<<n<<" "<<n-1<<endl;
    // long long int answer = ((long long int) n)*(n-1);
    // cout<<answer<<endl; 
    
    ans=((((long long int)n)*(n-1))/2) - ans;
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int p = stoi(first_multiple_input[1]);

    vector<vector<int>> astronaut(p);

    for (int i = 0; i < p; i++) {
        astronaut[i].resize(2);

        string astronaut_row_temp_temp;
        getline(cin, astronaut_row_temp_temp);

        vector<string> astronaut_row_temp = split(rtrim(astronaut_row_temp_temp));

        for (int j = 0; j < 2; j++) {
            int astronaut_row_item = stoi(astronaut_row_temp[j]);

            astronaut[i][j] = astronaut_row_item;
        }
    }

    long long int result = journeyToMoon(n, astronaut);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
