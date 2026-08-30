class Solution {
public:
    vector<int> getPrime(int n){
        vector<int> v;
        if(n%2==0){
            v.emplace_back(2);
            while(n%2==0){
                n=n/2;
            }

        }
        for(int i=3;i*i<=n;i+=2){
            if(n%i==0){
               v.push_back(i);
                while(n%i==0){
                    n=n/i;
                }
            }
          
        }
        if(n>1){
          v.push_back(n);
        }
        return v;
        
    }
    int longestSubarray(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        int i=0;
        int j=0;
        int d=0;
        int max_len=0;
        int n=nums.size();
        while(j<n){
            vector<int> primes=getPrime(nums[j]);
            for(int p:primes){
                if(freq[p]==0) d++;
                freq[p]++;
            }
            while(d>k){
                vector<int> lp=getPrime(nums[i]);
                for(int p:lp){
                    freq[p]--;
                    if(freq[p]==0) {
                        d--;
                        freq.erase(p);
                    }
                }
                i++;
            }
            max_len=max(max_len,j-i+1);
            j++;
        }
        return max_len;
    }
};