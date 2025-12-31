//Sequence Pattern Matching

#include<bits/stdc++.h>
using namespace std;

int LCS(string &s, string &p){
    int m=s.size(), n=p.size();

    //dp table
    vector<vector<int>>dp(m+1, vector<int>(n+1, 0));

    //choice diagram
    for(int i=1; i<m+1; i++){
        for(int j=1; j<n+1; j++){
            if(s[i-1]==p[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
            }
            else{
                dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    
    return dp[m][n];
}

bool isMatch(string s, string p){
    if(LCS(s,p)==s.size())return true;
    return false;
}