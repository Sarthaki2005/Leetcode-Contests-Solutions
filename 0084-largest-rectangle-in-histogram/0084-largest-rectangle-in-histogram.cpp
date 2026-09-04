class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
        auto get=[&](vector<int> &arr){
         int n=arr.size();
         vector<int> output(n,-1);
         stack<int> st;
         st.push(0);
         for(int i=1;i<n;i++){
            while(!st.empty() && arr[i]<arr[st.top()]){
                output[st.top()]=i;
                st.pop();
            }
            st.push(i);
         }
         return output;
        };
        int n=arr.size();
        int max_area=0;
        vector<int> nse=get(arr);
        vector<int> temp=arr;
        reverse(temp.begin(),temp.end());
        vector<int> pse=get(temp);
        reverse(pse.begin(),pse.end());
        for(int i=0;i<n;i++){
            int ns=nse[i];
            int ps=(pse[i]==-1)?-1:n-1-pse[i];     //pse bcoz we reversed it it gave the index in reversed form if it would have been value it would have be correct.....
            if(ns==-1) ns=n;
            int area=(ns-ps-1)*arr[i];
            max_area=max(area,max_area);
        }
        // for(auto x:nse) cout<<x<<" ";
        // cout<<"\n";
        // for(auto x:pse) cout<<x<<" ";
        // cout<<"\n";
        return max_area;
    }
};