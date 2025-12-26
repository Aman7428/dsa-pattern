#include<bits/stdc++.h>
using namespace std;

//Return the fewest number of coins that you need to make up that amount.
int coinChange(vector<int>& coins, int amount){
    //wt->coins
    //W->amount

    int n=coins.size();

    //dp table
    vector<vector<int>>dp(n+1, vector<int>(amount+1));

    //initialization
    //when array is empty then infinite no. of coins are required to make a certain amount
    for(int j=0; j<amount+1; j++)dp[0][j]=INT_MAX-1; //-1 to avoid int overflow

    //when amount is 0 then no coin is required
    for(int i=1; i<n+1; i++)dp[i][0]=0;

    //when coin array only contain 1 element i.e coin[0] then (no. of coin required)=amount/coin[0];
    for(int j=1; j<amount+1; j++){
        if(j%coins[0]==0){
            dp[1][j]=j/coins[0];
        }
        else dp[1][j]=INT_MAX-1; //otherwise infinte coins required to make certain amount
    }

    //choice diagram
    for(int i=2; i<n+1; i++){
        for(int j=1; j<amount+1; j++){
            if(coins[i-1]<=j){
                dp[i][j]=min(1+dp[i][j-coins[i-1]], dp[i-1][j]);
            }
            else dp[i][j]=dp[i-1][j];
        }
    }

    return dp[n][amount];
}



//clean code
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();

        //dp table
        vector<vector<int>>dp(n+1, vector<int>(amount+1, INT_MAX-1));

        //initialisation
        //base case
        dp[0][0]=0;
        //if  amount=0 then (no. of coin required)=0
        for(int i=1; i<n+1; i++)dp[i][0]=0;

        //choice diagram
        for(int i=1; i<n+1; i++){
            for(int j=1; j<amount+1; j++){
                if(coins[i-1]<=j){
                    dp[i][j]=min(1+dp[i][j-coins[i-1]], dp[i-1][j]);
                }
                else dp[i][j]=dp[i-1][j];
            }
        }
        return dp[n][amount] >= INT_MAX-1 ? -1 : dp[n][amount];
    }
};