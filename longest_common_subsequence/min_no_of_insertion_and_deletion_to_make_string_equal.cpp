//Minimum Number of Insertion and Deletion to convert String a to String b
//let, m=a.size(), n=b.size(), x=LCS(string a, string b)
//(min. no. of deletion)=m-LCS(a,b)
//(min. no. of insertion)=n-LCS(a,b)

#include<bits/stdc++.h>
using namespace std;

int LCS(string a, string b){
    int m=a.size(), n=b.size();

    //dp table
    vector<vector<int>>dp(m+1, vector<int>(n+1, 0));

    //choice diagram
    for(int i=1; i<m+1; i++){
        for(int j=1; j<n+1; j++){
            if(a[i-1]==b[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
            }
            else{
                dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    return dp[m][n];
}

// Function to return pair {insertions, deletions}
pair<int,int> minimumInsertionAndDeletion(string a, string b){
    int m = a.size(), n = b.size();
    
    int lcs = LCS(a,b);

    int deletions = m - lcs; 
    int insertions = n - lcs;

    return {insertions, deletions};
}