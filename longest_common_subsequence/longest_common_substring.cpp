#include<bits/stdc++.h>
using namespace std;

int longestCommonSubstring(string& s1, string& s2){
    int m=s1.size(), n=s2.size(), ans=0;
    
    //dp table
    vector<vector<int>>dp(m+1, vector<int>(n+1, 0));

    //choice diagram
    for(int i=1; i<m+1; i++){
        for(int j=1; j<n+1; j++){
            if(s1[i-1]==s2[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
                ans=max(ans, dp[i][j]);
            }
            else{
                dp[i][j]=0;
            }
        }
    }

    return ans;
}