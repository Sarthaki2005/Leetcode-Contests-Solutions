class Solution {
public:
    int nearestDrone(vector<vector<int>>& drones, vector<int>& target) {
        int idx=-1;
        int dist=1e9;
        int tx=target[0];
        int ty=target[1];
        for(int i=0;i<drones.size();i++){
            int x=drones[i][0];
            int y=drones[i][1];
            int r=drones[i][2];

            int d=abs(x-tx)+abs(y-ty);
            if(d<=r){
                if(d<dist){
                    dist=d;
                    idx=i;
                }
            }
        }
        return idx;
    }
};
