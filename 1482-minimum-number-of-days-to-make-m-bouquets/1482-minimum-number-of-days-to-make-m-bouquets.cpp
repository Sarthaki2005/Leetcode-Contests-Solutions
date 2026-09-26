class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n=bloomDay.size();
        int low=*min_element(bloomDay.begin(),bloomDay.end());
        int high=*max_element(bloomDay.begin(),bloomDay.end());
        int res=-1;
        while(low<=high){
            int  mid=low+(high-low)/2;
            int cnt=0,ans=0;
            for(int i=0;i<n;i++){
               if(bloomDay[i]<=mid){
                cnt++;
               }else{
                ans+=cnt/k;
                cnt=0;
               }
            }
            ans+=cnt/k;
            if(ans>=m){
                res=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return res;
    }
};