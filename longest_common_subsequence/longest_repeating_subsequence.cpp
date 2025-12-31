//Longest repeating subsequence
//Given string str, find the length of the longest repeating subsequence such that it can be found twice in the given string
//For example, A = "xax" and B = "xax" then the index of the first "x" must be different in the original string for A and B.

#include<bits/stdc++.h>
using namespace std;

int LongestRepeatingSubsequence(string &s){
    string str=s;
    int m=s.size(), n=str.size();

    //dp table
    vector<vector<int>>dp(m+1, vector<int>(n+1, 0));

    //choice diagram
    for(int i=1; i<m+1; i++){
        for(int j=1; j<n+1; j++){
            if(i!=j && s[i-1]==str[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
            }
            else{
                dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    return dp[m][n];
}