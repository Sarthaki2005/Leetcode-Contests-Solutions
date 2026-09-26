class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        // vector<int> missing;
        // int start=1;
        // for(int i=0;i<arr.size();i++){
        //     int sec=arr[i]-1;
        //     for(int j=start;j<=sec;j++){
        //         missing.push_back(j);
        //     }
        //     start=arr[i]+1;

        // }
        // if(missing.size()>=k){
        //     return missing[k-1];
        // }
        //     int rem=k-missing.size();
        //  return start+rem-1;
        //simplest bruteforces 
        //[1 2 3 4 ]   k=2    
        //fisrt assumption __ __ 1,2 missing so ans=2
        //then 1 fills up the space so , _1_ __ __ so ans=3 might be possible the 2nd missing
        int ans=k;
        for(int i=0;i<arr.size();i++){
           if(arr[i]<=ans){
            ans++;
           }else{
            break;
           }
        }
        return ans;
    }
};