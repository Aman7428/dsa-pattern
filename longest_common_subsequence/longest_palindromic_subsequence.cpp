//Longest Palindromic Subsequence
//let string a is given
//let string b=reverse(a.begin(), a.end())
//now LCS(a,b)->is the longest palindromic subsequence 

#include<bits/stdc++.h>
using namespace std;

    int LCS(string s, string b) {
        int n = s.size(), m = b.size();

        //dp table
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

        //choice diagram
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(s[i-1] == b[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                } else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[n][m];
    }

    int longestPalindromeSubseq(string s) {
        string b = s;
        reverse(b.begin(), b.end());
        return LCS(s, b);
    }
