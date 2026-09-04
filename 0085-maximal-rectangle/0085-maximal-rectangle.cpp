class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        auto get=[&](vector<int> &arr){
            int n=arr.size();
            stack<int> st;
            st.push(0);
            int max_area=0;
            for(int i=1;i<n;i++){
                while(!st.empty() && arr[i]<arr[st.top()]){
                    int rhs=i;
                    int height=arr[st.top()];
                    st.pop();
                    int lhs=st.empty()?-1:st.top();
                    int area=(rhs-lhs-1)*height;
                    max_area=max(area,max_area);
                }
                st.push(i);
            }
            while(!st.empty()){
                int rhs=n;
                int height=arr[st.top()];
                st.pop();
                int lhs=st.empty()?-1:st.top();
                int area=(rhs-lhs-1)*height;
                max_area=max(max_area,area);
            }
            return max_area;
        };
        int n=matrix.size();
        int m=matrix[0].size();
        int max_area=0;
        vector<int> heights(m,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]=='1') heights[j]++;
                else heights[j]=0;
            }
            int area=get(heights);
            max_area=max(max_area,area);
        }
        return max_area;
    }
};