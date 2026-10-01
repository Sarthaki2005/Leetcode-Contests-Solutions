class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //Core idea if j-i+1 is substring with no repeating characters 
        //then unique_cnt in substring==j-i+1 bcoz at every position a new char wil be there
        int n=s.size();
        int i=0,j=0,unique_cnt=0;
        int ans=0;
        unordered_map<char,int> mp;
        while(j<n){
            mp[s[j]]++;
            if(mp[s[j]]==1) unique_cnt++;
            while(j-i+1>unique_cnt){
                mp[s[i]]--;
                if(mp[s[i]]==0) unique_cnt--;
                i++;
            }
            ans=max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};