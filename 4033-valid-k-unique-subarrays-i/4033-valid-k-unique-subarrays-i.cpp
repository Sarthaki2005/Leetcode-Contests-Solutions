

class Solution {
public:
    struct Query {
        int l, r, id;
        Query(int l = 0, int r = 0, int id = 0) : l(l), r(r), id(id) {}
    };

    vector<bool> validSubarrays(vector<int>& nums, int k, vector<vector<int>>& queries) {
        int n = nums.size();
        int m = queries.size();

        // 1. Coordinate Compression
        vector<int> temp = nums;
        sort(temp.begin(), temp.end());
        temp.erase(unique(temp.begin(), temp.end()), temp.end());
        for (int i = 0; i < n; i++) {
            nums[i] = lower_bound(temp.begin(), temp.end(), nums[i]) - temp.begin();
        }

        // 2. Prepare Queries
        vector<Query> query(m);
        for (int i = 0; i < m; i++) {
            query[i] = Query(queries[i][0], queries[i][1], i);
        }

        int B = max(1, (int)sqrt(n));

        // Sort queries using Mo's ordering
        sort(query.begin(), query.end(), [B](const Query &a, const Query &b) {
            int block_a = a.l / B;
            int block_b = b.l / B;
            if (block_a != block_b) return block_a < block_b;
            // return (block_a & 1) ? (a.r < b.r) : (a.r > b.r); 
             return a.r < b.r; 
        });

        // 3. Frequency Tracking & Mo's Processing
        int max_ele = temp.size();
        vector<int> freq(max_ele, 0);
        int distinct = 0,odd_freq=0;

        auto add = [&](int idx) {
            freq[nums[idx]]++;
            if( freq[nums[idx]]%2!=0) {odd_freq++;}else {
              odd_freq--;
            }
            if (freq[nums[idx]] == 1) {
                distinct++;
            }
        };

        auto remove = [&](int idx) {
            freq[nums[idx]]--;
            if(freq[nums[idx]]%2!=0) {odd_freq++;}else {odd_freq--;}
            if (freq[nums[idx]] == 0) {
                distinct--;
            }
        };

        vector<bool> ans(m);
        int currL = 0, currR = -1;

        for (int i = 0; i < m; i++) {
            auto q = query[i];

            while (currL > q.l) add(--currL);
            while (currR < q.r) add(++currR);
            while (currL < q.l) remove(currL++);
            while (currR > q.r) remove(currR--);

            
            ans[q.id] = (distinct == k && odd_freq==0); 
        }

        return ans;
    }
};