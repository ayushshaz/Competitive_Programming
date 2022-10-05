#include<bits/stdc++.h>
using namespace std;

void floodFill(char input[][50],int i,int j, char color){
    if(input[i][j]=='#' or input[i][j]==color){ // do not paint the already painted also.
        return;
    }
    if(i<0 && j<0 && i>8 && j>20){ //should be inside the wall
        return;
    }
    input[i][j]=color;

    floodFill(input,i+1,j,color);
    floodFill(input,i,j+1,color);
    floodFill(input,i-1,j,color);
    floodFill(input,i,j-1,color);
}
void printGraph(char input[][50],int x,int y){
    for(int i=0;i<x;i++){
        for(int j=0;j<y;j++){
            cout<<input[i][j];
        }
        cout<<"\n";
    }
}
int main(){
    int r,c;cin>>r>>c;
    char input[15][50];

    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin>>input[i][j];
        }
    }
    floodFill(input,3,8,'R');
    printGraph(input,r,c);
    return 0;
}

/*
8 20
....................
.....#######........
....#.......#.......
...#.........#......
...#..........#.....
...#...........#....
...#...........#....
...#############....

*/