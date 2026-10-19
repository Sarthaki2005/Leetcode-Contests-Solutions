class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n=nums.size();
        int i=0;
        int j=0;
        int sum=0,len=0,change=0;
        int ans=INT_MIN;
        while(j<n){
            sum+=nums[j];
              len=j-i+1;
              change=len-sum;
              while(change>0){
                sum-=nums[i];
                i++;
                len=j-i+1;
                change=len-sum;
              }
              ans=max(ans,len);
              j++;
        } 
        return ans;
    }
};