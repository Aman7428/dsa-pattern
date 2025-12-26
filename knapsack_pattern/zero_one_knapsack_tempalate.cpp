#include<bits/stdc++.h>
using namespace std;

//recursive approach->base condition+choice diagram
int knapsack(int W, vector<int>& wt, vector<int>& val, int n){
    //base condition
    if(n==0 || W==0)return 0;

    //choice diagram
    if(wt[n-1]<=W){
        return max(val[n-1]+knapsack(W-wt[n-1], wt, val, n-1), knapsack(W, wt, val, n-1));
    }
    else{
        return knapsack(W, wt, val, n-1);
    }
}



//Top down DP approach->(recursion+memoization)
    //dp table initialized with value -1
    vector<vector<int>dp(n+1, vector<int>(W+1, -1));
int knapsack(int W, vector<int>& wt, vector<int>& val, int n, vector<vector<int>>& dp){

    //base condition
    if(n==0 || W==0)return 0;

    if(dp[n][W]!=-1)return dp[n][W];

    //choice diagram
    if(wt[n-1]<=W){
        return dp[n][W]=max(val[n-1]+knapsack(W-wt[n-1], wt, val, n-1, dp) || knapsack(W, wt, val, n-1, dp));
    }
    else{
        return dp[n][W]=knapsack(W, wt, val, n-1, dp);
    }
}



//best DP approach->Bottom Up DP approach->(Iterative / Tabulation)
int knapsack(int W, vector<int>& wt, vector<int>& val, int n){
    //dp table
    vector<vector<int>>dp(n+1, vector<int>(W+1));

    //base case
    for(int i=0; i<n+1; i++){
        for(int j=0; j<W+1; j++){
            if(i==0 || j==0)dp[i][j]=0;
        }
    }

    //choice diagram
    for(int i=1; i<n+1; i++){
        for(int j=1; j<W+1; j++){
            if(wt[i-1]<=j){
                dp[i][j]=max(val[i-1]+dp[i-1][j-wt[i-1]], dp[i-1][j]);
            }
            else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }

    return dp[n][W];
}