#include<bits/stdc++.h>
using namespace std;

int CoinChange(vector<int>& coins, int amount){
    //changes in unbounded_knapsack
    //wt->coins
    //W->amount

    int n=coins.size();

    //dp table
    vector<vector<int>>dp(n+1, vector<int>(amount+1, 0));

    //initialisation
    for(int i=0; i<n+1; i++)dp[i][0]=1;

    //choice diagram
    for(int i=1; i<n+1; i++){
        for(int j=1; j<amount+1; j++){
            if(coins[i-1]<=j){
                dp[i][j]=dp[i][j-coins[i-1]]+dp[i-1][j];
            }
            else dp[i][j]=dp[i-1][j];
        }
    }
    return dp[n][amount];
}



//1d DP approach to avoid overflow
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<unsigned long long> dp(amount+1, 0);
        dp[0] = 1;

        for(int coin : coins){
            for(int j = coin; j <= amount; j++){
                dp[j] += dp[j - coin];
            }
        }

        return (int)dp[amount];
    }
};