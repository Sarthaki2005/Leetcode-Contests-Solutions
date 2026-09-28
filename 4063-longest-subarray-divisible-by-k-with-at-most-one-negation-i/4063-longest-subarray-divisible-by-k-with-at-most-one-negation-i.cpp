class Solution {
public:
using ll=long long;
    int longestSubarray(vector<int>& nums, int k) {
        int n=nums.size();
        int ans=0;
        for(int i=0;i<n;i++){
unordered_set<ll> st;
ll sum=0;
            for(int j=i;j<n;j++){
                 sum+=nums[j];
                 ll factor= ((2*nums[j])%(ll)k+(ll)k)%(ll)k;
                 st.insert(factor);
                 if(sum%k==0 || st.find((sum%(ll)k+(ll)k)%(ll)k)!=st.end()){
                    ans=max(ans,j-i+1);
                 }

            }
        }
        return ans;
    }
};