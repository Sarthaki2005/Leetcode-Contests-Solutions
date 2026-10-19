class Solution {
public:
    int characterReplacement(string s, int k) {
        
       vector<int> freq(26,0);
       int n=s.size();
       int i=0,j=0,ans=INT_MIN,max_freq=0;
       int len=0,change=0;
       while(j<n){
        freq[s[j]-'A']++;
        max_freq=max(max_freq,freq[s[j]-'A']);
        len=j-i+1;
        change=len-max_freq;
        while(change>k){
            freq[s[i]-'A']--;
            i++;
            max_freq=0;
            for(int i=0;i<26;i++){
                max_freq=max(max_freq,freq[i]);
            }
            len=j-i+1;
            change=len-max_freq;
        }
        ans=max(ans,len);
        j++;
       }
       return ans;
    }
};