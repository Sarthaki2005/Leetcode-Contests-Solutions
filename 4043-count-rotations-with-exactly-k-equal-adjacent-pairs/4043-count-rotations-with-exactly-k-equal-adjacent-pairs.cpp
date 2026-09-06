class Solution {
public:
    int countRotations(string s, int k) {
        int n=s.size();
        int ans=0;
        for(int i=0;i<n;i++){
           int cnt=0;
            for(int l=0;l<n-1;l++){
              if(s[(i+l)%n]==s[(i+l+1)%n]) cnt++;

            }
            if(cnt==k)  ans++;
        }
        return ans;
    }
};