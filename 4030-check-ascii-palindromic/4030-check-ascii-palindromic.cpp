class Solution {
public:
   string getBinary(int num){
    string res="";
    while(num!=1){
        int rem=num%2;
        num=num/2;
        res+=(rem+'0');
    }
    
    res.push_back(1+'0');
if(res.size()!=8) {
    int remaining=8-res.size();
    while(remaining--){
        res+=('0');
    }
}
    reverse(res.begin(),res.end());
    return res;
   }
   bool isPalindrome(string &s){
    int i=0;
    int j=s.size()-1;
    while(i<=j){
        if(s[i]!=s[j]){
            return false;
        }
        i++;
        j--;
    }
    return true;
   }
    bool isPalindromic(string s) {
        string ans="";
        for(int i=0;i<s.size();i++){
            int num=int(s[i]);
            ans+=getBinary(num);
        }
cout<<ans<<"\n";
        if(isPalindrome(ans)) return true;
        return false;
    }
};