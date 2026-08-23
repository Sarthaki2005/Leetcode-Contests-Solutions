class Solution {
public:
using ll=long long;
struct Segment{
int n;
vector<ll> t;
vector<ll> lazy;
Segment(int n):n(n),t(4*n,0),lazy(4*n,0){}
void push(int v,int tl,int tr){
    if(lazy[v]!=0){
        int tm=(tl+tr)/2;
        t[2*v+1]+=(tm-tl+1)*lazy[v];
        t[2*v+2]+=(tr-tm)*lazy[v];
        lazy[2*v+1]+=lazy[v];
        lazy[2*v+2]+=lazy[v];
        lazy[v]=0;
    }
}
void update(int v,int tl,int tr,int l,int r,ll x){
    if(l>r) return ;
    if(tl==l && tr==r){
        t[v]+=(tr-tl+1)*x;
        lazy[v]+=x;
        return;
    }
    push(v,tl,tr);
    int tm=(tl+tr)/2;
    update(2*v+1,tl,tm,l,min(tm,r),x);
    update(2*v+2,tm+1,tr,max(l,tm+1),r,x);
    t[v]=t[2*v+1]+t[2*v+2];
}
ll query(int v,int tl,int tr,int l,int r){
    if(l>r) return 0;
    if(tl==l && tr==r) return t[v];
    push(v,tl,tr);
    int tm=(tl+tr)/2;
    ll left=query(2*v+1,tl,tm,l,min(tm,r));
    ll right=query(2*v+2,tm+1,tr,max(l,tm+1),r);
    return left+right;
}
};
    long long minInitialStrength(vector<int>& monsters, vector<vector<int>>& boosts) {
        int n=monsters.size();
        
        // Segment st(n);
        // for(auto ele:boosts){
        //     st.update(0,0,n-1,ele[0],ele[1],ele[2]);
        // }

        vector<ll> diff(n+1,0);
        for(auto ele:boosts){
            int l=ele[0];int r=ele[1]; ll x=(ll)ele[2];
            diff[l]+=x;
            diff[r+1]-=x;
        }
        vector<ll> pref(n,0);
        pref[0]=diff[0];
        for(int i=1;i<n;i++){
            pref[i]=diff[i]+pref[i-1];
        }
        
        ll sum=0;
        for(auto x:monsters){
            sum+=x;
        }
        long long ans=0;
        ll low=0;
        ll high=sum;
        while(low<=high){
            ll mid=(low+high)/2;
            //check whether this can be minimum
        ll start=mid;
            bool ok=true;
            for(int i=0;i<n;i++){
                ll boost=pref[i];
                if(start+boost>=(ll)monsters[i]){
                    start=max((ll)0,(ll)start-monsters[i]);
                }else{
                    ok=false;
                    break;
                }
            }
            if(ok) {
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return ans;
    }
};