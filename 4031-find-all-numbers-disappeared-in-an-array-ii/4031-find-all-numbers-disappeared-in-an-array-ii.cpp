class Solution {
public:
    vector<vector<int>> findDisappearedNumbers(vector<int>& nums, int lower, int upper) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        // if(upper<=nums[0]){
        //     if(upper==nums[0]){
        //         return {{lower,upper-1}};
        //     }else{
        //         return {{lower,upper}};
        //     }
        // }else if(lower>=nums.back()){
        //     if(lower==nums.back()){
        //         return {{lower+1,upper}};
        //     }else{
        //         return {{lower,upper}};
        //     }
        // }
        vector<vector<int>> res;
        int i=0;
        int l=lower;
        while(i<n && l<=upper){
            if(l<nums[i]){
                int u=min(nums[i]-1,upper);
                res.push_back({l,u});
                
            }
            l=max(nums[i]+1,lower);
            i++;
        }
        if(upper>=l){
            res.push_back({l,upper});
           
        }
       if(res.size()==0){
        return {};
       }
       return res;
    }
};