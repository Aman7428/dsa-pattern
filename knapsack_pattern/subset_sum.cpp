#include<bits/stdc++.h>
using namespace std;

bool isSubsetSum(vector<int>& arr, int sum){
    int n=arr.size();

    //dp table
    vector<vector<int>dp(n+1, vector<int>(sum+1));

    //initialization
    for(int i=0; i<n+1; i++){
        for(int j=0; j<sum+1; j++){
            if(i==0)dp[i][j]=false; //arr.size()=0
            if(j==0)dp[i][j]=true;  //sum=0->empty subset possible
        }
    }

    //choice diagram
    for(int i=1; i<n+1; i++){
        for(int j=1; j<sum+1; j++){
            if(arr[i-1]<=j){
                dp[i][j]=(dp[i-1][j-arr[i-1]] || dp[i-1][j]);
            }
            else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }

    return dp[n][sum];
}