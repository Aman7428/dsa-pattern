#include<bits/stdc++.h>
using namespace std;

//recursive approach
int LCS(string X, string Y, int m, int n){
    //base condition
    if(n==0 || m==0)return 0;

    //choice diagram
    if(X[m-1]==Y[n-1]){
        return 1+ LCS(X, Y, m-1, n-1);
    }
    else{
        return max(LCS(X, Y, m-1, n), LCS(X, Y, m, n-1));
    }
}



//top-down approach (recursion + memoization)
class Solution {
private:
    int solve(string &text1, string &text2, int m, int n, vector<vector<int>>& dp){

        //base condition
        if(m==0 ||n==0)return 0;

        if(dp[m][n]!=-1)return dp[m][n];

        //choice diagram
        if(text1[m-1]==text2[n-1]){
            return dp[m][n]=1+solve(text1, text2, m-1, n-1, dp);
        }

        return dp[m][n]=max(solve(text1, text2, m-1, n, dp), solve(text1, text2, m, n-1, dp));
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m=text1.size(), n=text2.size();
        //dp table
        vector<vector<int>>dp(m+1, vector<int>(n+1, -1));
        return solve(text1, text2, m, n, dp);

    }
};



//bottom Up DP approach
#include<bits/stdc++.h>
using namespace std;

int LCS(string text1, string text2){
    int m=text1.size(), n=text2.size();
    
    //dp table
    vector<vector<int>>dp(m+1, vector<int>(n+1, 0));

    // choice diagram
    for(int i=1; i<m+1; i++){
        for(int j=1; j<n+1, j++){
            if(text1[i-1]==text2[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
            }
            else{
                dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    return dp[m][n];
}