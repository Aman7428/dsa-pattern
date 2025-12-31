//Printing Longest common subsequence
#include<bits/stdc++.h>
using namespace std;

string printLCS(string &s1, string &s2){
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

    //create substring by traversing dp table from bottom corner->bactracking dp table
    int i=m, j=n;
    string ans="";

    while(i>0 && j>0){
        if(s1[i-1]==s2[j-1]){
            ans.push_back(s1[i-1]);
            i--;
            j--;
        }
        else{
            if(dp[i][j-1]> dp[i-1][j])j--;
            else i--;
        }
    }

    //reverse the string ans
    reverse(ans.begin(), ans.end());

    return ans;
}