// // class Solution {
// // public:
// // using ll=long long;
// // vector<ll> evenPal;
// // vector<ll> oddPal;
// // bool first=false;
// //  ll makeEven(ll x) {
// //         ll res = x;

// //         while (x > 0) {
// //             res = res * 10 + x % 10;
// //             x /= 10;
// //         }

// //         return res;
// //     }

// //     ll makeOdd(ll x) {
// //         ll res = x;
// //         x /= 10;

// //         while (x > 0) {
// //             res = res * 10 + x % 10;
// //             x /= 10;
// //         }

// //         return res;
// //     }
// // void generate(ll mx){
// //     first=true;
// //    for(int i=1;i<=10000;i++){
// //      ll p1 = makeEven(i);
// //             ll p2 = makeOdd(i);
// // if (p1 <= mx) {
// //                 if (p1 % 2 == 0)
// //                     evenPal.push_back(p1);
// //                 else
// //                     oddPal.push_back(p1);
// //             }

// //             if (p2 <= mx) {
// //                 if (p2 % 2 == 0)
// //                     evenPal.push_back(p2);
// //                 else
// //                     oddPal.push_back(p2);
// //             }
// //         }

      
   
// //    sort(evenPal.begin(),evenPal.end());
// //    sort(oddPal.begin(),oddPal.end());

// // }
// //     long long minOperations(vector<int>& nums) {
// //         if(!first) generate(1e9);
// //         ll minops=0;
        
// //         for(int i=0;i<nums.size();i++){
// //             ll min_x=1e18;
// //               if(nums[i]%2==0){
// //                auto it=lower_bound(evenPal.begin(),evenPal.end(),nums[i]);
// //                if(it!=evenPal.end()) {
// //                 ll ops1=(*it-nums[i])/2;
// //                 min_x=min(min_x,ops1);
// //                }
// //                if(it!=evenPal.begin()){
// //                 ll ops2=abs(*prev(it)-nums[i])/2;
// //                 min_x=min(min_x,ops2);
// //                }
// //               }else{
// //  auto it=lower_bound(oddPal.begin(),oddPal.end(),nums[i]);
// //                if(it!=oddPal.end()) {
// //                 ll ops1=(*it-nums[i])/2;
// //                 min_x=min(min_x,ops1);
// //                }
// //                if(it!=oddPal.begin()){
// //                 ll ops2=abs(*prev(it)-nums[i])/2;
// //                 min_x=min(min_x,ops2);
// //                }
// //               }
// //               minops+=min_x;
// //         }
// //         return minops;
// //     }
// // };

// class Solution {
// public:
//     using ll = long long;

//     vector<ll> evenPal, oddPal;
//     bool generated = false;

//     void generate() {
//         if (generated) return;
//         generated = true;

//         for (ll i = 1; i <= 99999; i++) {

//             // Odd length
//             ll x = i;
//             ll p = i;
//             x /= 10;

//             while (x) {
//                 p = p * 10 + x % 10;
//                 x /= 10;
//             }

//             if (p <= 1000000000LL) {
//                 if (p & 1)
//                     oddPal.push_back(p);
//                 else
//                     evenPal.push_back(p);
//             }

//             // Even length
//             x = i;
//             p = i;

//             while (x) {
//                 p = p * 10 + x % 10;
//                 x /= 10;
//             }

//             if (p <= 1000000000LL) {
//                 if (p & 1)
//                     oddPal.push_back(p);
//                 else
//                     evenPal.push_back(p);
//             }
//         }

//         sort(evenPal.begin(), evenPal.end());
//         sort(oddPal.begin(), oddPal.end());

//         evenPal.erase(unique(evenPal.begin(), evenPal.end()), evenPal.end());
//         oddPal.erase(unique(oddPal.begin(), oddPal.end()), oddPal.end());
//     }

//     long long minOperations(vector<int>& nums) {

//         vector<int> virelqunox = nums;

//         generate();

//         ll ans = 0;

//         for (ll x : virelqunox) {

//             vector<ll>& pal = (x & 1) ? oddPal : evenPal;

//             auto it = lower_bound(pal.begin(), pal.end(), x);

//             ll best = LLONG_MAX;

//             if (it != pal.end()) {
//                 best = min(best, (*it - x) / 2);
//             }

//             if (it != pal.begin()) {
//                 --it;
//                 best = min(best, (x - *it) / 2);
//             }

//             ans += best;
//         }

//         return ans;
//     }
// };


using ll = long long;
vector<ll> od, ev;
bool initDone = false;

class Solution {
public:
    void init() {
        if (initDone) return;
        
        for (int len = 1; len <= 10; ++len) {
            int k = (len - 1) / 2;
            ll start = 1;
            for (int i = 0; i < k; i++) start *= 10;
            ll end = start * 10;

            for (ll i = start; i < end; ++i) {
                ll p = i;
                ll temp = i;
                
                if (len % 2 != 0) temp /= 10;
                
                while (temp > 0) {
                    p = p * 10 + (temp % 10);
                    temp /= 10;
                }
                
                if (p % 2 == 0) ev.push_back(p);
                else od.push_back(p);
            }
        }
        initDone = true;
    }

    ll getMeGreater(vector<ll>& temp, int x){
        ll o = 1e18;
        auto it = lower_bound(temp.begin(), temp.end(), x);

            if(it != temp.end()){
                o = min(o, 1LL*(abs(x - *it)));
            }

            if(it != temp.begin()){
                auto p = prev(it);
                o = min(o, 1LL*(abs(x - *p)));
            }

        return o;
    }

    ll getMeSmaller(vector<ll>& temp, int x){
        int i = 0, j = temp.size() - 1;

        ll it = -1;
        while(i <= j){
            int mid = (i + j)/2;
            if(temp[mid] <= x){
                it = mid;
                i = mid + 1;
            }else j = mid - 1;
        }
        if(it == -1) return 1e18;
        return x - temp[it];
    }

    
    ll minOperations(vector<int>& a) {
        init();
        
        ll ans = 0;
        for(auto x: a){
            ll o = 1e18;
            if(x&1){
                o = getMeGreater(od, x);
                o = min(o, getMeSmaller(od, x));
            }
            else{
                o = getMeGreater(ev, x);
                o = min(o, getMeSmaller(ev, x));
            }
            
            if(o != 1e18) ans += o;
        }
        return ans/2;
        
    }
};