class Solution {
public:
vector<int> rotate(vector<int> &nums){
    int num=nums.back();
    nums.pop_back();
    vector<int> res;
    res.push_back(num);
    res.insert(res.end(),nums.begin(),nums.end());
    return res;
}
    bool check(vector<int>& nums) {
        int n=nums.size();
        vector<int> temp=nums;
        for(int i=0;i<n;i++){
           if(is_sorted(temp.begin(),temp.end())) return true;
           temp=rotate(temp);
        }
        return false;
    }
};