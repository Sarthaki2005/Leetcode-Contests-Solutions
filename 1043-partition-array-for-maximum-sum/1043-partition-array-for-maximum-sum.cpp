class Solution {
public:
int f(int ind,vector<int> &arr,vector<int> &dp,int n,int k){
    if(ind>=n) return 0;
    if(dp[ind]!=-1) return dp[ind];
    int max_ans=-1e9;
    int max_ele=-1e9;
    
    for(int j=ind;j<min(ind+k,n);j++){
        max_ele=max(arr[j],max_ele);
        int sum=max_ele*(j-ind+1)+f(j+1,arr,dp,n,k);
        max_ans=max(max_ans,sum);
    }
    return dp[ind]=max_ans;
}
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int> dp(n,-1);
        return f(0,arr,dp,n,k);
    }
};