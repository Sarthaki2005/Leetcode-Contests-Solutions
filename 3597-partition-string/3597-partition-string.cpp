class Solution {
public:
    vector<string> partitionString(string s) {
        set<string> seen;
        string t="";
        vector<string> v;
        int n=s.size();
        for(int i=0;i<n;i++){
            t+=s[i];
            if(seen.count(t)) continue;
            seen.insert(t);
            v.push_back(t);
            t="";
        }
        return v;
    }
};