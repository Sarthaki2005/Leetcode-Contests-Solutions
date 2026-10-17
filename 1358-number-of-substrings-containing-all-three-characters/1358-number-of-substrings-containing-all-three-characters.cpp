class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.size();
        int i=0;
        int j=0;
        vector<int> freq(3,0);
        int distinct=0;
        int ans=0;
        while(j<n){
           freq[s[j]-'a']++;
           if(freq[s[j]-'a']==1) distinct++;
           while(distinct==3){
            freq[s[i]-'a']--;
            if(freq[s[i]-'a']==0) distinct--;
            i++;

           }
           ans+=i;
           j++;
        }
        return ans;
    }
};