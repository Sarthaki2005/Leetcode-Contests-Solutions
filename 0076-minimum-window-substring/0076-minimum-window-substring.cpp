class Solution {
public:
    string minWindow(string s, string t) {
        // int n=s.size();
        // int startIdx=-1,len=0;
        // for(int i=0;i<n;i++){
        //     int cnt=0;
        //     vector<int> hashMap(256,0);
        //     for(int j=0;j<t.size();j++){
        //         hashMap[t[j]]++;
        //     }
        //     for(int j=i;j<n;j++){
        //         if(hashMap[s[j]]>0) cnt+=1;
        //         hashMap[s[j]]-=1;
        //         if(cnt==t.size()){
        //             if(startIdx==-1 || len>j-i+1){
        //                 startIdx=i;
        //                 len=j-i+1;
        //             }
        //         }
        //     }
        // }
        // if(startIdx==-1) return "";
        // return s.substr(startIdx,len);
        int n=s.size();
        int l=0,r=0,cnt=0,ans=n+1;
        int startIdx=-1,len=INT_MAX;
        vector<int> freq(256,0);
        for(int i=0;i<t.size();i++){
            freq[t[i]]++;
        }
        while(r<n){
            if(freq[s[r]]>0) {
                cnt+=1;
            }
            freq[s[r]]-=1;
            while(cnt==t.size() && freq[s[l]]<0){
                freq[s[l]]+=1;
                l++;
            }
            if(cnt==t.size()){
              if(r-l+1<len){
                startIdx=l;
                len=r-l+1;
              }
            }
          r++;
        }
        if(startIdx==-1) return "";
return s.substr(startIdx,len);
    }
};