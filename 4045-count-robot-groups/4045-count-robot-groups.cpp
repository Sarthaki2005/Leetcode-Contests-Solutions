class Solution {
public:
    int countGroups(vector<int>& position, vector<int>& speed, int distance) {
        int n=position.size();
        int ans=n;
        int ms=speed[n-1];
        for(int i=n-2;i>=0;i--){
            if(speed[i]>ms || position[i+1]-position[i]<=distance){
                ans--;
            }else{
                ms=speed[i];
            }
        }
        return ans;
    }
};