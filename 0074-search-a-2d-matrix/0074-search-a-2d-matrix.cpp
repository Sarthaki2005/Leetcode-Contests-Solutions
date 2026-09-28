class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        //hypothetically flatten the 2d array
      int low=0;
      int high=m*n-1;
      while(low<=high){
        int mid=low+(high-low)/2;
        int block_no=mid/m;
        int offset=mid%m;
        if(matrix[block_no][offset]==target) return true;
        else if(matrix[block_no][offset]>target) high=mid-1;
        else low=mid+1;
      }
      return false;

    }
};