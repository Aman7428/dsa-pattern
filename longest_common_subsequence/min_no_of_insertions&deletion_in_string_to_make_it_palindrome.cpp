//Minimum number of insertion/deletion in a string to make it a palindrome
//let string s is given such that, int m=s.size()
//let string b=reverse(s.begin(), s.end())
//min. no. of insertions/deletions in s to make it palindrome=m-LCS(s,b)

#include<bits/stdc++.h>
using namespace std;

//longest palindromic sequence
int LCS(string &s, string &b){
    int m=s.size(), n=b.size();

    //dp table
    vector<vector<int>>dp(m+1, vector<int>(n+1, 0));

    //choice diagram
    for(int i=1; i<m+1; i++){
        for(int j=1; j<n+1; j++){
            if(s[i-1]==b[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
            }
            else{
                dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    return dp[m][n];
}

int minDeletionToMakePalindrome(string s){
    int m=s.size();
    string b=s;
    reverse(b.begin(), b.end());
    return m-LCS(s,b);
}