class Solution {
public:
using ll=long long;
ll check(int rot,string s){
    int start=rot;
    int n=s.size();
    int end=(start-1+n)%n;
    int cnt=n/2;
    ll sum=0;
    while(cnt--){
        int d1=s[start]-'a';
        int d2=s[end]-'a';
       int diff=abs(d1-d2);
       sum+=min(diff,26-diff);
        start=(start+1)%n;
        end=(end-1+n)%n;
    }
    return sum;
}
    int minOperations(string s) {
        int n=s.size();
       ll min_ans=1e18;
        if(n%2==0){
            for(int i=0;i<=n/2;i++){
             min_ans=min(min_ans,i+check(i,s));
            }
           
            // in each rotation calculate the num of inc opr
        }
        else{
             for(int i=0;i<=n-1;i++){
             min_ans=min(min_ans,i+check(i,s));
            }
            //n rotation
            //in each roation calcute the num of inc to make palindrome
        }
        return min_ans;
    }
};