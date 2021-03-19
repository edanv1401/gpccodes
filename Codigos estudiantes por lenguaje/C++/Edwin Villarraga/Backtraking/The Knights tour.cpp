#include<bits/stdc++.h>
#include<cstdlib>
#define N 8
using namespace std;
void printSolution(int sol[N][N]){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cout<<sol[i][j]<<"\t";
        }
        cout<<endl;
    }
}
bool isSafe(int x,int y,int sol[N][N]){
    if(x>=0 && x<N && y>=0 && y<N && sol[x][y]==-1){
        return 1;
    }
    return 0;
}
int solveKTUtil(int x,int y,int movei,int movex[],int movey[],int sol[N][N]){
    if(movei==N*N){
        return 1;
    }
    for(int i=0;i<8;i++){
        int next_x=x+movex[i];
        int next_y=y+movey[i];
        if(isSafe(next_x,next_y,sol)){
            int &ans=sol[next_x][next_y];
            ans=movei;
            if(solveKTUtil(next_x,next_y,movei+1,movex,movey,sol)){
                return 1;
            }
            else{
                ans=-1;
            }
        }
    }
    return 0;
}
int solveKT(){
    int movex[8]={2, 1,-1,-2,-2,-1, 1, 2};
    int movey[8]={1, 2, 2, 1,-1,-2,-2,-1};
    int sol[N][N];
    memset(sol,-1,sizeof(sol));
    sol[0][0]=0;
    if(solveKTUtil(0,0,1,movex,movey,sol)){
        printSolution(sol);
        return 0;
    }else{
        cout<<"Not Solution"<<endl;
    }
    return 1;

}
int main() {
    solveKT();
    return 0;
}

