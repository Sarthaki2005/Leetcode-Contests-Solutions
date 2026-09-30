class Solution {
public:
    int f(int k,int l,string &s){
      
       int n=s.size();
        
       while(k>=0 && l<n){
        if(s[k]!=s[l]) break;
        k--;
        l++;
       }
       
       return l-k-1;
    }
    string longestPalindrome(string s) {
        int max_len=1;
        int n=s.size();
        int ans_i=0;
        int ans_j=0;
        for(int i=0;i<n;i++){
            //odd len
            int len=f(i,i,s);
            
            if(len>max_len){
                 ans_i=i-(len/2);
                 ans_j=i+len/2;
                 max_len=len;
                //  cout<<"ODD LEN AT "<<ans_i<<" "<<ans_j<<" when at "<<i<<"\n";
            }
            
             
            //even len
            if(i+1<n && s[i]==s[i+1]){
                 len=f(i,i+1,s);
           
            if(len>max_len){
                 ans_i=i-(len/2)+1;;
                 ans_j=i+(len/2);
                 max_len=len;
                //   cout<<"EVEN LEN AT "<<ans_i<<" "<<ans_j<<" when at "<<i<<"\n";
            }
            }
        }
string res="";
for(int start=ans_i;start<=ans_j;start++){
    res+=s[start];
}
return res;
    }
};