using ll=long long;
vector<ll> evenPal;
vector<ll> oddPal;
bool first=false;
class Solution {
public:


void generate(ll mx){
    first=true;
   for(int i=1;i<=100000;i++){
    string a=to_string(i);
    string b=a;
    reverse(a.begin(),a.end());
    //Even pal
    ll num=stoll(b+a);
    if(num<=mx){
        if(num%2==0) evenPal.push_back(num);
        else oddPal.push_back(num);
    }
    //OddPal
    b.pop_back();
    num=stoll(b+a);
    if(num<=mx){
        if(num%2==0) evenPal.push_back(num);
        else oddPal.push_back(num);
    }
   }
   sort(evenPal.begin(),evenPal.end());
   sort(oddPal.begin(),oddPal.end());

}
    long long minOperations(vector<int>& nums) {
        if(!first) generate(1e9);
        ll minops=0;
        
        for(int i=0;i<nums.size();i++){
            ll min_x=1e18;
              if(nums[i]%2==0){
               auto it=lower_bound(evenPal.begin(),evenPal.end(),nums[i]);
               if(it!=evenPal.end()) {
                ll ops1=(*it-nums[i])/2;
                min_x=min(min_x,ops1);
               }
               if(it!=evenPal.begin()){
                ll ops2=abs(*prev(it)-nums[i])/2;
                min_x=min(min_x,ops2);
               }
              }else{
 auto it=lower_bound(oddPal.begin(),oddPal.end(),nums[i]);
               if(it!=oddPal.end()) {
                ll ops1=(*it-nums[i])/2;
                min_x=min(min_x,ops1);
               }
               if(it!=oddPal.begin()){
                ll ops2=abs(*prev(it)-nums[i])/2;
                min_x=min(min_x,ops2);
               }
              }
              minops+=min_x;
        }
        return minops;
    }
};