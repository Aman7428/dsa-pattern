#include<bits/stdc++.h>
using namespace std;

int minSubSetSumDifference(vector<int>& nums){
    //calculate sum
    int sum=0, n=nums.size();

    for(int i=0; i<n; i++){
        sum=sum+nums[i];
    }

    //dp table
    vector<vector<bool>>dp(n+1, vector<bool>(sum+1));

    //initialisation
    for(int i=0; i<n+1; i++){
        for(int j=0; j<sum+1; j++){
            if(i==0)dp[i][j]=false; //nums.size()=0
            if(j==0)dp[i][j]=true; //sum=0
        }
    }

    //choice diagram
    for(int i=1; i<n+1; i++){
        for(int j=1; j<sum+1; j++){
            if(nums[i-1]<=j){
                dp[i][j]=(dp[i-1][j-nums[i-1]] || dp[i-1][j]);
            }
            else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }

    //vector of size n having true value
    vector<int>vec;
    for(int j=0; j<sum+1; j++){
        if(dp[n][j]==true)vec.push_back(j);
    }

    //s1+s2=sum -> s2=sum-s1 ->s2-s1=sum-2*s1
    //track the minimum difference 
    int diff=INT_MAX;

    for(int i=0; i<vec.size(); i++){
        diff=min(diff, abs(sum-2*vec[i]));
    }

    return diff;
}



//clean code->same hi hai but cleaner version hai...
#include<bits/stdc++.h>
using namespace std;

int minSubSetSumDifference(vector<int>& nums){
    int n = nums.size();
    int sum = accumulate(nums.begin(), nums.end(), 0);

    vector<vector<bool>> dp(n+1, vector<bool>(sum+1, false));

    // initialization
    for(int i = 0; i <= n; i++)
        dp[i][0] = true;

    // DP
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= sum; j++){
            if(nums[i-1] <= j)
                dp[i][j] = dp[i-1][j] || dp[i-1][j - nums[i-1]];
            else
                dp[i][j] = dp[i-1][j];
        }
    }

    int diff = INT_MAX;
    for(int j = 0; j <= sum/2; j++){
        if(dp[n][j])
            diff = min(diff, sum - 2*j);
    }

    return diff;
}
