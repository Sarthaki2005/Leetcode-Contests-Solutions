class Solution {
public:
    bool kmp(string &heystack,string &needle){
        int m=needle.size();
        vector<int> lps(m+1,0);
        int pref=0,suff=1;
        while(suff<m){
            if(needle[pref]==needle[suff]){
                lps[suff]=pref+1;
                suff++;
                pref++;
            }
            else{
                if(pref==0){
                    lps[suff]=0;
                    suff++;
                }else{
                    pref=lps[pref-1];
                }
            }
        }
        int n=heystack.size();
        int i=0,j=0;
        while(i<n && j<m){
            if(heystack[i]==needle[j]){
                i++;
                j++;
            }else{

                if(j==0) i++;
                else{
                    j=lps[j-1];
                }
            }
        }
        if(j==m) return true;
        return false;
    }
    int repeatedStringMatch(string a, string b) {
        int n=a.size();
        int m=b.size();
        int k=(m+n-1)/n;
        string orig="";
       for(int i=0;i<k;i++){
        orig+=a;
       }
        bool ans=kmp(orig,b);
        if(ans) return k;
        orig+=a;
        ans=kmp(orig,b);
        if(ans) return k+1;
        return -1;


    }
};