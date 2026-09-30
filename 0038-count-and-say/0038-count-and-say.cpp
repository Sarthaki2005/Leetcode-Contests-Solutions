class Solution {
public:
    string countAndSay(int n) {
        if(n==1) return "1";
        string t=countAndSay(n-1);
        string res="";
        int m=t.size();
        char c=t[0];
        int cnt=1;
        for(int i=1;i<m;i++){
            if(t[i]==c){
                cnt++;
            }else{
                res+=to_string(cnt);
                res+=c;
                cnt=1;
                c=t[i];
            }
        }
        res+=to_string(cnt);
        res+=c;
        // cout<<res<<"\n";
return res;
    }
};