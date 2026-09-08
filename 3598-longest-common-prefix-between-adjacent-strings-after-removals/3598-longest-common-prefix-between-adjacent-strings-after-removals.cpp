class Solution {
public:
    vector<int> longestCommonPrefix(vector<string>& words) {
        int n=words.size();
        vector<int> prefix(n,0);
        vector<int> suffix(n,0);
        for(int j=0;j<n-1;j++){
            string s=words[j];
            string t=words[j+1];
            int i=0;
            int len=min(s.size(),t.size());
            while(i<len){
                if(s[i]!=t[i]) break;
                i++;
            }
           if(j!=0) prefix[j]=max(prefix[j-1],i);
           else prefix[j]=i;

        }
        for(int j=n-1;j>0;j--){
             string s=words[j];
            string t=words[j-1];
            int i=0;
            int len=min(s.size(),t.size());
            while(i<len){
                if(s[i]!=t[i]) break;
                i++;
            }
           if(j!=(n-1)) suffix[j]=max(suffix[j+1],i);
           else suffix[j]=i;
        }
        vector<int> v(n,0);
   for(int i=0;i<n;i++){
    int left=0,right=0;
    if(i-2>=0) left=prefix[i-2];
    if(i+2<n) right=suffix[i+2];
    int j=0;
    if(i-1>=0 && i+1<n){
         string s=words[i-1];
            string t=words[i+1];
            
            int len=min(s.size(),t.size());
            while(j<len){
                if(s[j]!=t[j]) break;
                j++;
            }
    }
   v[i]=max(left,max(j,right));
    
   }
   return v;
    }
};