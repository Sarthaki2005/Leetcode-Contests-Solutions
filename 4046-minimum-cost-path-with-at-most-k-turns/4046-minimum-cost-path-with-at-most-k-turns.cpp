class Solution {
public:
    int minCost(vector<vector<int>>& grid, int k) {
        int n=grid.size();
        int m=grid[0].size();
       vector<vector<vector<vector<int>>>> dist(n,vector<vector<vector<int>>>(m,vector<vector<int>>(5,vector<int>(k+1,INT_MAX))));
        dist[0][0][4][k]=grid[0][0];
        using State=tuple<int,int,int,int,int>;
        priority_queue<State,vector<State>,greater<State>> pq;
        pq.push({grid[0][0],0,0,4,k});
        vector<tuple<int,int,int>>  directions={{0,-1,0},{-1,0,1},{0,1,2},{1,0,3}};
        while(!pq.empty()){
            auto [cost,i,j,ld,remk]=pq.top();
            pq.pop();
            if(i==n-1 && j==m-1) return cost;
            if(cost>dist[i][j][ld][remk]) continue;
            for(auto [dx,dy,d]:directions){
                int nx=i+dx;
                int ny=j+dy;
                if(nx<0 || nx>=n || ny<0 || ny>=m) continue;
                int newk=remk;
                if(ld!=4 && d!=ld){
                    if(remk==0) continue;
                        newk--;
                }
                int new_cost=cost+grid[nx][ny];
                if(new_cost<dist[nx][ny][d][newk]){
                    dist[nx][ny][d][newk]=new_cost;
                    pq.push({new_cost,nx,ny,d,newk});
                }

            }
        }
        return -1;
    }
};