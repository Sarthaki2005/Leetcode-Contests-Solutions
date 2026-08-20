class Solution {
public:
using ll=long long;
const ll INF=1e18;
    long long elevatorRequests(int n, int start, vector<vector<int>>& requests) {
       int m=requests.size();
       vector<vector<ll>> dp((1<<m),vector<ll>(m,INF));
       //initialize
       for(int j=0;j<m;j++){
        int mask=1<<j;
        int a=requests[j][0];
        int floor=requests[j][1];
       ll newTime=max((ll)abs(start-floor),(ll)a);
        dp[mask][j]=min(dp[mask][j],newTime);
       }
       for(int mask=0;mask<(1<<m);mask++){
        for(int i=0;i<m;i++){
            if(dp[mask][i]==INF) continue;
            for(int j=0;j<m;j++){
                if(mask & (1<<j)) continue;
                int lastFloor=requests[i][1];
                int nextFloor=requests[j][1];
                int arr=requests[j][0];
                ll newTime=max(dp[mask][i]+(ll)abs(lastFloor-nextFloor),(ll)arr);
                int newMask=mask|(1<<j);
                dp[newMask][j]=min(dp[newMask][j],newTime);
            }
        }
       }
       ll min_time=INF;
       int nm=(1<<m)-1;
       //[1111][with diff j being last visited]
       for(int j=0;j<m;j++){
            min_time=min(min_time,dp[nm][j]);
       }
       return min_time;
    }
};