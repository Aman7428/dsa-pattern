#include<bits/stdc++.h>
using namespace std;

    int findTargetSumWays(vector<int>& nums, int target) {
        //sum(s1)-sum(s2)=target
        //sum(s1)+sum(s2)=sum(nums)
        //sum(s1)=(sum(nums)+target)/2->count subset having, goal=sum(s1);

        int n=nums.size(), sum=0;
        for(int i=0; i<n; i++){
            sum=sum+nums[i];
        }
        
        if(sum < abs(target) || (sum + target) % 2 != 0) return 0; // critical checks

        int goal = (sum + target) / 2;
        if(goal < 0) return 0;

        //dp table
        vector<vector<int>>dp(n+1, vector<int>(goal+1, 0));

        //initialization
        dp[0][0]=1;

        //choice diagram
        for(int i=1; i<n+1; i++){
            for(int j=0; j<goal+1; j++){
                if(nums[i-1]<=j){
                    dp[i][j]=(dp[i-1][j-nums[i-1]] + dp[i-1][j]);
                }
                else dp[i][j]=dp[i-1][j];
            }
        }
        return dp[n][goal];
    }