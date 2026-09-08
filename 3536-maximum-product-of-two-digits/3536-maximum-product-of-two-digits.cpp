class Solution {
public:
    int maxProduct(int n) {
        vector<int> digits;
        while(n>0){
            int rem=n%10;
            n=n/10;
            digits.push_back(rem);
        }
        sort(digits.begin(),digits.end());
        int s=digits.size();
       return digits[s-1]*digits[s-2];
    }
};