#include<bits/stdc++.h>
using namespace std;

int cutRod(vector<int>& price){
    //changes in unbounded_knapsack
    //W->N or n->length of rod
    //val->price
    //wt->length

    int n=price.size();

    //length array
    vector<int>length;
    for(int i=0; i<n; i++){
        length.push_back(i+1);
    }

    //dp table
    vector<vector<int>>dp(n+1, vector<int>(n+1, 0));

    //choice diagram
    for(int i=1; i<n+1; i++){
        for(int j=1; j<n+1; j++){
            if(length[i-1]<=j){
                dp[i][j]=max(price[i-1]+dp[i][j-length[i-1]], dp[i-1][j]);
            }
            else dp[i][j]=dp[i-1][j];
        }
    }

    return dp[n][n];
}