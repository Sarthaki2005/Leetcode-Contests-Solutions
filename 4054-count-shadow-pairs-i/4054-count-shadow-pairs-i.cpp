class Solution {
public:
using ll=long long;
    long long shadowPairs(vector<int>& nums) {
       vector<int> st;
        ll valid=0;
        for(int i=0;i<nums.size();i++){
            int x=nums[i];
            while(!st.empty() && st.back()>x ){
                st.pop_back();
            }
            if(!st.empty())
            {
                auto it=lower_bound(st.begin(),st.end(),x)-st.begin();
                valid+=it;
               
            }
             st.push_back(x);
        }
        return valid;
    }
};