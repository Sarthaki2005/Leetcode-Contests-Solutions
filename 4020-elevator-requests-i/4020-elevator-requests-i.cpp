class Solution {
public:
    int elevatorRequests(int n, vector<int>& requests) {
        int m=requests.size();
        int curr=0;
        int sum=0;
        for(int i=0;i<m;i++){
          sum+=abs(curr-requests[i]);
          curr=requests[i];
        }
        return sum;
    }
};