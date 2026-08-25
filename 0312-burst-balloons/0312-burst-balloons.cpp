class Solution {
public:
int f(int i,int j,vector<int> &nums,vector<vector<int>> &dp){
    if(i>j) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    int max_coins=-1e9;
    for(int k=i;k<=j;k++){
        int steps=f(i,k-1,nums,dp)+f(k+1,j,nums,dp)+nums[i-1]*nums[k]*nums[j+1];
        max_coins=max(max_coins,steps);
    }
    return dp[i][j]=max_coins;
}
    int maxCoins(vector<int>& nums) {
         int n=nums.size();
        nums.insert(nums.begin(),1);
       
        nums.emplace_back(1);
       vector<vector<int>> dp(n+2,vector<int>(n+2,-1));
        return f(1,n,nums,dp); 
    }
};