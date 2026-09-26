class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        vector<int> missing;
        int start=1;
        for(int i=0;i<arr.size();i++){
            int sec=arr[i]-1;
            for(int j=start;j<=sec;j++){
                missing.push_back(j);
            }
            start=arr[i]+1;

        }
        if(missing.size()>=k){
            return missing[k-1];
        }
            int rem=k-missing.size();
         return start+rem-1;
        
    }
};