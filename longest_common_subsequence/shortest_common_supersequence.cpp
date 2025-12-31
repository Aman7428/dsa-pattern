//print length of Shortest Common SuperSequence
//let, s1.size()=m, s2.size()=n, LCS(s1,s2)=a
//so (length of Shortest Common SuperSequence)=(m+n-a)
//example:
// s1 = "abc", s2 = "ac"
// LCS = "ac" -> length = 2
// SCS length = 3 + 2 - 2 = 3
// Shortest Common Supersequence = "abc"


#include<bits/stdc++.h>
using namespace std;

int LCS(string &s1, string &s2){
    int m=s1.size(), n=s2.size();

    //dp table
    vector<vector<int>>dp(m+1, vector<int>(n+1, 0));

    //choice diagram
    for(int i=1; i<m+1; i++){
        for(int j=1; j<n+1; j++){
            if(s1[i-1]==s2[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
            }
            else{
                dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    return dp[m][n];
}

int lengthOfShortestCommonSuperSequence(string s1, string s2){
    int m=s1.size(), n=s2.size();
    return m+n-LCS(s1, s2);
}