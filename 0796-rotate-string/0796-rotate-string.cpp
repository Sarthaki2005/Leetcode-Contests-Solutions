class Solution {
public:
    void rotate(string &s){
        int n=s.size();
        char c=s[0];
        for(int i=0;i<n-1;i++){
            s[i]=s[i+1];
        }
        s[n-1]=c;
    }
    bool rotateString(string s, string goal) {
        int n=s.size();
        if(s==goal) return true;
        for(int i=0;i<n-1;i++){
            rotate(s);
            if(s==goal) return true;
        }
        return false;
    }
};