class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& locked, int k) {
        int n=nums.size();
        int cnt=0;
        //min number of swaps ==number ofinversion
        //each swap eliminates atmost 1 inversion
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(nums[i]>nums[j]) cnt++;
        }
    }
      //whether i is part of any inversion interval
      vector<int> prefMax(n);
      vector<int> suffixMin(n);
      for(int i=0;i<n;i++){
        if(i==0) prefMax[i]=nums[i];
        else prefMax[i]=max(prefMax[i-1],nums[i]);
      }
      for(int i=n-1;i>=0;i--){
        if(i==n-1) suffixMin[i]=nums[i];
        else suffixMin[i]=min(suffixMin[i+1],nums[i]);
      }
         int c=0;
         for(int i=0;i<n;i++){
            if(prefMax[i]>suffixMin[i] && locked[i]==1) c++;
         }

    if(c>k) return -1;
    return cnt+c;
    }
};