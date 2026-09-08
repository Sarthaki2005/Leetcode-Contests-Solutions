class Solution {
public:
int N;
int solve(int i,int k,int currRate,vector<int> &position,vector<int> &time,vector<vector<vector<int>>> &dp){
    if(i==N-1) {
        if(k>0) return INT_MAX;
        else return 0;
      
    }
     if(dp[i][k][currRate]!=-1) return dp[i][k][currRate];
    int result=INT_MAX;
    //no merging like connecting i to i+2,connecting i to i+3
    int skipped=solve(i+1,k,time[i+1],position,time,dp);
    if(skipped!=INT_MAX){
        int dist=(position[i+1]-position[i])*currRate;
        result=min(result,skipped+dist);
    }


//not skipped
if(k>0){
    //i+1 gayab ho jayega toh uska time store karlo
    int mergeTime=time[i+1];
    int mergeCount=0;
    for(int j=i+2;j<N && mergeCount<k;j++){
        mergeCount++;
        mergeTime=mergeTime+time[j];
        int take=solve(j,k-mergeCount,mergeTime,position,time,dp);
        if(take!=INT_MAX){
            int d=(position[j]-position[i])*currRate;
             result=min(result,take+d);
        }
       
    }

}
return dp[i][k][currRate]=result;
}
    int minTravelTime(int l, int n, int k, vector<int>& position, vector<int>& time) {
        N=n;
        int cumTime=0;
        for(int i=0;i<n;i++) cumTime+=time[i];
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(k+1,vector<int>(cumTime+1,-1))); 
        return solve(0,k,time[0],position,time,dp);
    }
};