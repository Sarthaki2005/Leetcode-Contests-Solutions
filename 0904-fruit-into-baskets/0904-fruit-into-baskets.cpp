class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int> freq;
        int n=fruits.size();
        int i=0;
        int j=0;
        int distinct=0;
        int ans=0;
        while(j<n){
             freq[fruits[j]]++;
             if(freq[fruits[j]]==1) distinct++;
             while(distinct>2){
                freq[fruits[i]]--;
                if(freq[fruits[i]]==0){
                    distinct--;
                }
                i++;
             }
             ans=max(ans,j-i+1);
             j++;
         }
return ans;
    }
};