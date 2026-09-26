class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int n=weights.size();
       
        int low=*max_element(weights.begin(),weights.end());
        int high=(*max_element(weights.begin(),weights.end()))*n;
        int res=-1;
        while(low<=high){

            int mid=low+(high-low)/2;
            int cnt=0;
            int sum=0;
            for(int i=0;i<n;i++){
                if(sum+weights[i]>mid){
                    cnt++;
                    sum=weights[i];
                }else{
                    sum+=weights[i];
                }

            }
            cnt++;
               if(cnt<=days){
                res=mid;
                high=mid-1;

               }else{
            low=mid+1;
               }
        
        }

        return res;

    }
};