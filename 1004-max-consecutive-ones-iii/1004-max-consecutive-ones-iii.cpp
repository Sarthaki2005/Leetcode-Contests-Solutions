class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();
        int i=0,j=0,sum=0,len=0,change=0;
        int ans=INT_MIN;
        while(j<n){
            sum+=nums[j];
            len=j-i+1;
            change=len-sum;
            while(change>k){
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