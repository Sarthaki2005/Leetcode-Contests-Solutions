class Solution {
public:
    int countValidPrefixes(string s) {
        int n=s.size();
        vector<int> prefix(n,0);
        for(int i=0;i<n;i++){
            if(i!=0) prefix[i]=(s[i]-'0')+prefix[i-1];
            else prefix[i]=(s[i]-'0');
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            int num=i+1;
            int ones=prefix[i];
            int zeros=num-ones;
            if(abs(ones-zeros)<=1) cnt++;
        }
        return cnt;
    }
};