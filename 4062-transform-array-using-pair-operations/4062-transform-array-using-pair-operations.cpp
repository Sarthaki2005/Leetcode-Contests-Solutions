class Solution {
public:
using ll=long long;
    bool canTransform(vector<int>& source, vector<int>& target) {
        int n1=source.size();
        int n2=target.size();
        if(n1!=n2) return false;
        ll sum1=accumulate(source.begin(),source.end(),0LL);
        ll sum2=accumulate(target.begin(),target.end(),0LL);
        cout<<sum1<<"  "<<sum2<<"\n";
        if(sum1==sum2) return true;
        return false;
    }
};