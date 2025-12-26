#include<bits/stdc++.h>
using namespace std;

int CountNumberOfSubsetWithGivenDifference(vector<int>& arr, int diff){
    //sum(s1)+sum(s2)=sum(arr)
    //sum(s1)-sum(s2)=diff
    //sum(s1)=(sum(arr)+diff)/2 -> so we have to count the no. of subset having, target=sum(s1)

    int n = arr.size(), sum = 0;
    for(int x : arr) sum += x;

    if((sum + diff) % 2 != 0) return 0;  // target must be integer
    int target = (sum + diff) / 2;
    
    //dp table
    vector<vector<int>> dp(n+1, vector<int>(target+1, 0));

    //initialisation
    dp[0][0] = 1; // There's 1 way to make sum 0 (pick nothing)

    //choice diagram
    for(int i=1; i<=n; i++){
        for(int j=0; j<=target; j++){
            if(arr[i-1] <= j){
                dp[i][j] = dp[i-1][j] + dp[i-1][j-arr[i-1]];
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    return dp[n][target];
}