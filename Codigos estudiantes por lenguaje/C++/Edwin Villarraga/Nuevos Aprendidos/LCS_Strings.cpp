#include <bits/stdc++.h>
#define len(x) x.size()
using namespace std;
using ll = long long int;
int main(){
    string s,p;
    cin>>s>>p;
    int n=len(s),m=len(p);
    vector<vector<int>>dp(n,vector<int>(m,-1));
    function<int(int,int)> lcs =[&](int i , int j){
        if(i >= n || j>= m){
            return 0;
        }
        int& ans = dp[i][j];
        if(ans != -1)return ans;
        ans = 0;
        ans = max(ans,lcs(i+1,j));
        ans = max(ans,lcs(i,j+1));
        if(s[i]==p[j]){
            ans = max(ans,lcs(i+1,j+1)+1);
        }
        return ans;
    };

    function<void(int,int)> build_lcs =[&](int i , int j){
        if(i >= n || j>= m){
            return;
        }
        if(lcs(i,j)==lcs(i+1,j)){
            build_lcs(i+1,j);
            return;
        }
        if(lcs(i,j)==lcs(i,j+1)){
            build_lcs(i,j+1);
            return;
        }
        cout<<s[i];
        build_lcs(i+1,j+1);
    };
    build_lcs(0,0);
}
