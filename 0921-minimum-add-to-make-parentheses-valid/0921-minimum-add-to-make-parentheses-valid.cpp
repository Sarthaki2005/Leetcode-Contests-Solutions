class Solution {
public:
    int minAddToMakeValid(string s) {
        int cnt_open=0;
        int ans=0;
        for(int i=0;i<s.size();i++){
            if(s[i]==')'){
                if(cnt_open==0){
                    ans++;

                }else{
                    cnt_open--;
                }
            }else{
                cnt_open++;
            }
        }
        ans+=cnt_open;
        return ans;
    }
};