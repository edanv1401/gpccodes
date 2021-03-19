#include <bits/stdc++.h>
#include <cstdlib>
#define N 5
using namespace std;
void printSolution(int sol[N][N]){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cout<<sol[i][j]<<"\t";
        }
        cout<<endl;
    }
}
bool isSafe(int x,int y,int maze[N][N]){
    if(x>=0 && x<N && y>=0 && y<N && maze[x][y]==1){
        return true;
    }
    return false;
}
bool MSolveUtil(int x,int y,int sol[N][N],int maze[N][N]){
    if(x==N-1 && y==N-1 && maze[x][y]==1){
        sol[x][y]=1;
        return true;
    }
    if(isSafe(x,y,maze)){
        if(sol[x][y]==1){
            return false;
        }
        sol[x][y]=1;
        if(MSolveUtil(x+1,y,sol,maze)){
            return true;
        }
        if(MSolveUtil(x,y+1,sol,maze)){
            return true;
        }
        if(MSolveUtil(x-1,y,sol,maze)){
            return true;
        }
        if(MSolveUtil(x,y-1,sol,maze)){
            return true;
        }
        sol[x][y]=0;
        return false;
    }
    return false;
}
void MSolve(int maze[N][N]){
    int sol[N][N];
    memset(sol,0,sizeof(sol));
    if(MSolveUtil(0,0,sol,maze)){
        printSolution(sol);
        return;
    }
    cout<<"No Solution"<<endl;
}
int main(){
    int maze[N][N]={{1,0,0,1,1},
                    {1,1,0,0,1},
                    {0,1,0,0,1},
                    {1,1,0,1,0},
                    {0,1,1,1,1}};
    MSolve(maze);

}
