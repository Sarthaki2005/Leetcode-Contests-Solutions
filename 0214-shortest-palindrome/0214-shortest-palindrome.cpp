class Solution {
public:
    string shortestPalindrome(string s) {
        //find longest palindromic prefix using kmp
        //take string s 
        //reverse the string temp=srev
        //s+="$"  to avoid overlapping
        //s+=srev
        //then perform kmp  to find longest prefix suffix match
        int n=s.size();
        string temp=s;
        reverse(temp.begin(),temp.end());
        s+="$";
        s+=temp;
        vector<int> lps(2*n+1,0);
        int pref=0,suff=1;
        while(suff<=2*n){
            if(s[pref]==s[suff]){
                lps[suff]=pref+1;
                pref++;
                suff++;
            }else{
                if(pref==0){
                    lps[suff]=0;
                    suff++;
                }else{
                    pref=lps[pref-1];
                }
            }
        }
        int ans=n-lps[2*n];
        string add=temp.substr(0,ans);
        string res=add;
        reverse(temp.begin(),temp.end());
        res+=temp;
        return res;


    }
};