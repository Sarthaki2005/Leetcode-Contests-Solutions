class Solution {
public:
vector<int> dp;

bool isPalindrome(int i,int j,string &s){
   
    while(i<=j){
        if(s[i]!=s[j]) return false;
        i++;
        j--;
    }
    return true;
}
int f(int i,string &s){
    
  if(i==s.size()) return 0;
  if(dp[i]!=-1) return dp[i];
    int min_ans=1e9;
    for(int k=i;k<s.size();k++){
        if(isPalindrome(i,k,s)){
            int steps=1+f(k+1,s);
            min_ans=min(min_ans,steps);
        }
    }
    return dp[i]=min_ans;
    

}
    int minCut(string s) {
        int n=s.size();
        dp.assign(n,-1);
       
        return f(0,s)-1;
    }
};