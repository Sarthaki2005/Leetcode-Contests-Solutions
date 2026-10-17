class Solution {
public:
   int atMostK(vector<int>& nums, int goal){
    int n=nums.size();
    int i=0;
    int j=0;
    int sum=0;
    int ans=0;
    while(j<n){
        sum+=nums[j];
        while(sum>goal){
            sum-=nums[i];
            i++;
        }
        ans+=(j-i+1);
        j++;
    }
    return ans;
   }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        if(goal==0) return atMostK(nums,goal);
        return atMostK(nums,goal)-atMostK(nums,goal-1);
    }
};