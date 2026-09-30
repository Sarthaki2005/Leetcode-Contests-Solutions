class Solution {
public:
   int getMinMax(vector<int> &freq){
    int maxi=INT_MIN,mini=INT_MAX;
    for(auto x:freq){
        maxi=max(maxi,x);
        if(x!=0) mini=min(mini,x);
    }
    return maxi-mini;
   }
    int beautySum(string s) {
        int n=s.size();
        int sum=0;
        for(int i=0;i<n;i++){
         vector<int> pref(26,0);
            for(int j=i;j<n;j++){
              pref[s[j]-'a']++;
             
              sum+=getMinMax(pref);
            }
        }
        return sum;
    }
};