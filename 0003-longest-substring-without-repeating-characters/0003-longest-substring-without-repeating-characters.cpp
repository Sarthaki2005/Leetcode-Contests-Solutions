class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        int distinct=0;
        int i=0,j=0;
        int ans=0;
        unordered_map<char,int> mp;
        while(j<n){
           mp[s[j]]++;
            if(mp[s[j]]==1) distinct++;
            while(distinct!=j-i+1){
              mp[s[i]]--;
                if(mp[s[i]]==0) distinct--;
                i++;
            }
            ans=max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};