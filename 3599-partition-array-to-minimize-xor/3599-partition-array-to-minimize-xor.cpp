class Solution {
public:
    int f(int idx, int k, vector<int>& nums, vector<int>& prefix,vector<vector<int>> &dp) {
        int n = nums.size();

        // Only one segment remaining
        if (k == 1) {
            return prefix[n - 1] ^ (idx > 0 ? prefix[idx - 1] : 0);
        }
       if(dp[idx][k]!=-1) return dp[idx][k];
        int ans = INT_MAX;

        int xor_v = 0;

        // Leave at least k-1 elements for k-1 segments
        for (int j = idx; j <= n - k; j++) {

            xor_v ^= nums[j];

            int remaining = f(j + 1, k - 1, nums, prefix,dp);

            int cost = max(xor_v, remaining);

            ans = min(ans, cost);
        }

        return dp[idx][k]=ans;
    }

    int minXor(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> prefix(n);
vector<vector<int>> dp(n,vector<int>(k+1,-1));
        prefix[0] = nums[0];

        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] ^ nums[i];
        }

        return f(0, k, nums, prefix,dp);
    }
};