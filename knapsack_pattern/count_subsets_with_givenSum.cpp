#include<bits/stdc++.h>
using namespace std;

//Bottom Up DP
int CountSubSetwithGivenSum(vector<int>& arr, int sum){
    //dp table
    vector<vector<int>>dp(n+1, vector<int>(sum+1,0));

    //base condition
    dp[0][0]=1;

    //choice diagram
    for(int i=1; i<n+1; i++){
        for(int j=0; j<sum+1; j++){
            if(arr[i-1]<=j){
                dp[i][j]=dp[i-1][j-arr[i-1]]+dp[i-1][j];
            }
            else dp[i][j]=dp[i-1][j];
        }
    }
    return dp[n][sum];
}


//recursive approach
int solve(int i, int sum){
    //base condition
    if(i==n){
        if(sum==target)return 1;
        return 0;
    }
    //choice diagram
    int take=solve(i+1, sum+arr[i]);
    int notTake=solve(i+1, sum);

    return take+notTake;
}
class Solution {
  public:
    int CountSubSetwithGivenSum(vector<int>& arr, int sum) {
        // code here
        return solve(0,0);
    }
};