class Solution {
public:

    int minPenalty(int period, vector<int>& lights, vector<int>& arrivalTime) {
        int m=arrivalTime.size();
        sort(lights.begin(),lights.end());
        int max_wait=0;
        for(int i=0;i<m;i++){
            int rem=arrivalTime[i]%period;
            auto it=upper_bound(lights.begin(),lights.end(),rem);
            if(it==lights.end()){
               int diff=period-rem;
               max_wait=max(max_wait,diff);
            }
        }
       return max_wait;
    }
};
