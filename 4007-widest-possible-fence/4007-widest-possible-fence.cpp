class Solution {
public:
using ll=long long;
    int maximumWidth(vector<int>& planks) {
        unordered_map<ll,int> mp;
       for(auto x:planks){
        mp[x]++;
       }
       int max_ans=0;
        vector<ll> st;
        for(auto &[val,freq]:mp) st.push_back(val);
       
         unordered_map<ll,int> ans;
         for(auto x:st){
            ans[x]=mp[x];
         }
           for(int i=0;i<st.size();i++){
            for(int j=i;j<st.size();j++){
                ll x=st[i];
                ll y=st[j];
                ll h=x+y;
                if(x==y){
                    ans[h]+=mp[x]/2;
                }else{
                    ans[h]+=min(mp[x],mp[y]);
                }
            }
           }
           for(auto &[h,width]:ans){
            max_ans=max(max_ans,width);
           }
          return max_ans;
    }
};