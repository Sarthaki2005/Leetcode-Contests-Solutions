// // class Solution {
// // public:
// //     using ll=long long;
// //     ll power(ll a,ll b){
// //         ll res=1;
// //         while(b>0){
// //             if(b%2!=0) res=res*a;
// //             a=a*a;
// //             b=b/2;
// //         }
// //         return res;
// //     }
// //     ll Digits(ll d){
// //         return 9*d*power(10,d-1);
// //     }
// //     int kthDigit(long long k) {
// //         if(k<=9) return k;
// //         k-=9;
// //         ll d=2;
        
// //         while(true){
// //             ll sub=Digits(d);
// //            if(k<=sub) break;
// //            k-=sub;
// //             d++;
           
// //         }
      

// //         ll cnt=0;
// //         ll par=10*d;
// //         while(k>par){
// //             k-=par;
// //             cnt++;
// //         }
// //         ll b_start=power(10,d-2);
// //         ll b_new=b_start+cnt;
// //         ll num_start,num_end;
// //         if(b_new%2==0){
// //              num_start=10*b_new;
// //              num_end=10*b_new+9;
// //         }else{
// // num_start=10*b_new+9;
// // num_end=10*b_new;
// //         }
// //         cnt=0;
// //         while(k>d){
// //             k-=d;
// //             cnt++;
// //         }
// //         ll num_new;
// //         if(b_new%2==0){
// //             num_new=num_start+cnt;
// //         }else{
// //             num_new=num_start-cnt;
// //         }
// //        vector<int> v;
// //         while(num_new>0){
// //             int dig=num_new%10;
// //             num_new=num_new/10;
// //             v.push_back(dig);
// //         }
// //         reverse(v.begin(),v.end());
// //            return v[k-1];
// //     }
// // };


// class Solution {
// public:
//     using ll = long long;

//     ll power(ll a, ll b) {
//         ll res = 1;
//         while (b > 0) {
//             if (b % 2 != 0) res = res * a;
//             a = a * a;
//             b = b / 2;
//         }
//         return res;
//     }

//     ll Digits(ll d) {
//         return 9 * d * power(10, d - 1);
//     }

//     int kthDigit(long long k) {
//         // Step 1: Handle Block 0 (1-digit numbers 1 through 9)
//         if (k <= 9) return k;

//         k -= 9;
//         ll d = 2;

//         // Step 2: Determine digit length d
//         while (true) {
//             ll count = Digits(d);
//             if (k <= count) break;
//             k -= count;
//             d++;
//         }


        
//         k--;

//         // Step 4: Determine block b_new
//         ll block_size = 10 * d;
//         ll block_offset = k / block_size;
//         ll b_start = power(10, d - 2);
//         ll b_new = b_start + block_offset;

//         // Step 5: Position within block b_new
//         ll pos_in_block = k % block_size;
//         ll num_index = pos_in_block / d;
//         ll digit_index = pos_in_block % d;

//         // Step 6: Determine number N (increasing if even b, decreasing if odd b)
//         ll N;
//         if (b_new % 2 == 0) {
//             N = 10 * b_new + num_index;
//         } else {
//             N = 10 * b_new + (9 - num_index);
//         }

//         // Step 7: Extract the target digit
//         string s = to_string(N);
//         return s[digit_index] - '0';
//     }
// };

class Solution{
    public:
using ll=long long;
ll power(ll a,ll b){
    ll res=1;
    while(b>0){
        if(b%2!=0){
            res*=a;
        }
        a*=a;
        b=b/2;
    }
    return res;
}
ll Digits(int d){
    return 9*d*power(10,d-1);
}
int kthDigit(long long k){
    if(k<=9) return k;
    k-=9;
    int d=2;
    while(true){
     ll cnt=Digits(d);
     if(cnt>=k){
        break;
     }
     k-=cnt;
     d++;
    }
    k--;
    ll block_size=10*d;
    ll block_offset=k/block_size;
    ll pos_in_block=k%block_size;
    ll b_start=power(10,d-2);
    ll b_new=b_start+block_offset;
    ll num_idx=pos_in_block/d;
    ll digit_idx=pos_in_block%d;
    ll N;
    if(b_new%2==0){
      N=10*b_new+num_idx;
    }else{
        N=10*b_new+(9-num_idx);
    }
    string s=to_string(N);
    return s[digit_idx]-'0';

}
};