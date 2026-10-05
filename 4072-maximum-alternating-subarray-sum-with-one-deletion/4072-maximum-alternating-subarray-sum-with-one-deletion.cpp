class Solution {
public:
    using ll = long long;
    const ll NEG = -(1LL << 60);

    long long maxAlternatingSum(vector<int>& nums) {
        ll plus0 = NEG;   // 0 deletions, last kept sign is +
        ll minus0 = NEG;  // 0 deletions, last kept sign is -

        ll plus1 = NEG;   // 1 deletion, last kept sign is +
        ll minus1 = NEG;  // 1 deletion, last kept sign is -

        ll ans = NEG;

        for (ll x : nums) {

            // No deletion
            ll nplus0 = max(0LL, minus0) + x;
            ll nminus0 = plus0 - x;

            // One deletion
            // Delete x: sign parity does NOT change.
            // Keep x: sign changes normally.
            ll nplus1 = max({
                minus1 + x,  // keep x after -
                plus0        // delete x, then previous state remains +
            });

            ll nminus1 = max({
                plus1 - x,   // keep x after +
                minus0       // delete x, previous state remains -
            });

            plus0 = nplus0;
            minus0 = nminus0;
            plus1 = nplus1;
            minus1 = nminus1;

            ans = max({ans, plus0, minus0, plus1, minus1});
        }

        return ans;
    }
};