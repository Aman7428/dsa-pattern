#include<bits/stdc++.h>
using namespace std;

bool SubSetSum(vector<int>& nums, int sum){
    int n=nums.size();

    //dp table
    vector<vector<int>>dp(n+1, vector<int>(sum+1));

    //initialization
    for(int i=0; i<n+1; i++){
        for(int j=0; j<sum+1; j++){
            if(i==0)dp[i][j]=false;
            if(j==0)dp[i][j]=true;
        }
    }

    //choice diagram
    for(int i=1; i<n+1; i++){
        for(int j=1; j<sum+1; j++){
            if(nums[i-1]<=j){
                dp[i][j]=max(dp[i-1][j-nums[i-1]], dp[i-1][j]);
            }
            else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }

    return dp[n][sum];
}

bool canPartiton(vector<int>nums){
    int n=nums.size(), sum=0;

    for(int i=0; i<n; i++){
        sum=sum+nums[i];
    }

    if(sum%2!=0)return false;
    else if(sum%2==0){
        return SubSetSum(nums,sum/2);
    }
}