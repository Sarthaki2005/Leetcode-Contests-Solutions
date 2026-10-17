class Solution {
public:
   int atmostK(vector<int>& nums, int k){
 int i=0;
        int j=0;
        int n=nums.size();
        int ans=0;
        int odd=0;
        while(j<n){
            if(nums[j]%2!=0){
                odd++;
            }
            while(odd>k){
                
                if(nums[i]%2!=0){
                    odd--;
                }
                i++;
            }
            ans+=(j-i+1);
            j++;
        }
        return ans;
   }
    int numberOfSubarrays(vector<int>& nums, int k) {
        
        return atmostK(nums,k)-atmostK(nums,k-1);
    }
};