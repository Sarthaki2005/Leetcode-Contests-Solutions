class Solution {
public:
using ll=long long;
    int countGoodRotations(vector<int>& nums) {
        int n=nums.size();
        int fp=0;
        int lp=n/2;
        int  cnt=0;
    ll origL=nums[fp];
    ll origR=nums[lp];
        ll leftSum=0,rightSum=0;
        for(int i=0;i<n/2;i++){
               leftSum+=nums[i];
        }
        for(int i=n/2;i<n;i++){
            rightSum+=nums[i];
        }
    for(int i=0;i<n;i++){
           if(leftSum>rightSum) cnt++;
           leftSum-=nums[fp];
           leftSum+=nums[lp];
           rightSum-=nums[lp];
           rightSum+=nums[fp];
           fp=(fp+1)%n;
           lp=(lp+1)%n;

        }
       
        return cnt;
    }
};