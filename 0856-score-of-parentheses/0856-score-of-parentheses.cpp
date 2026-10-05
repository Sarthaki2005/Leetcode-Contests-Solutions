class Solution {
public:
int f(int low,int high,string &s){
    if(low>high) return 0;
    if(high==low+1) return 1;
    
     int i=low;
        int j=low;
        int   cnt_open=0;
       
        int score=0;
        while(j<=high){
            if(s[j]=='(') cnt_open++;
            else {cnt_open--;
            if(cnt_open==0){
                if(j==i+1) score+=1;
                else score+=2*f(i+1,j-1,s);
                i=j+1;
            }
            }
             j++;
        }
        return score;
}
    int scoreOfParentheses(string s) {
       int low=0;
       int high=s.size()-1;
       return f(low,high,s);
    }
};