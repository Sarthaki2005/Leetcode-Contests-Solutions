#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // Fenwick Tree for minimum
    class BIT_MIN {
    public:
        int n, mx;
        vector<int> t;

        BIT_MIN(int n, int mx) : n(n), mx(mx), t(n + 1, mx) {}

        void update(int i, int val) {
            while (i <= n) {
                t[i] = min(t[i], val);
                i += i & -i;
            }
        }

        int query(int i) {
            int res = mx;

            while (i > 0) {
                res = min(res, t[i]);
                i -= i & -i;
            }

            return res;
        }

        void clear(int i) {
            while (i <= n) {
                t[i] = mx;
                i += i & -i;
            }
        }
    };


    // Fenwick Tree for maximum
    class BIT_MAX {
    public:
        int n;
        vector<int> t;

        BIT_MAX(int n) : n(n), t(n + 1, 0) {}

        void update(int i, int val) {
            while (i <= n) {
                t[i] = max(t[i], val);
                i += i & -i;
            }
        }

        int query(int i) {
            int res = 0;

            while (i > 0) {
                res = max(res, t[i]);
                i -= i & -i;
            }

            return res;
        }

        void clear(int i) {
            while (i <= n) {
                t[i] = 0;
                i += i & -i;
            }
        }
    };


    // Fenwick Tree for sum
    class BIT_SUM {
    public:
        int n;
        vector<int> t;

        BIT_SUM(int n) : n(n), t(n + 1, 0) {}

        void update(int i, int val) {
            while (i <= n) {
                t[i] += val;
                i += i & -i;
            }
        }

        int query(int i) {
            int res = 0;

            while (i > 0) {
                res += t[i];
                i -= i & -i;
            }

            return res;
        }
    };


    long long shadowPairs(vector<int>& nums) {

        int n = nums.size();

        // Coordinate compression
        vector<int> st = nums;

        sort(st.begin(), st.end());
        st.erase(unique(st.begin(), st.end()), st.end());

        int temp = st.size();

        vector<int> cv(n);

        for (int i = 0; i < n; i++) {
            cv[i] = lower_bound(
                st.begin(),
                st.end(),
                nums[i]
            ) - st.begin() + 1;
        }

        int s = temp + 2;
        int mx = temp + 1;

        BIT_MIN b_mn(s, mx);
        BIT_MAX b_mx(s);
        BIT_SUM b_sm(s);

        vector<int> lt(n, mx);
        vector<int> rt(n, 0);

        long long ans = 0;


        function<void(int,int)> cdq = [&](int l, int r) {

            if (l >= r)
                return;

            int m = l + (r - l) / 2;

            cdq(l, m);
            cdq(m + 1, r);


            // ---------------------------------
            // Calculate lt
            // ---------------------------------

            for (int i = m; i >= l; i--) {

                int val = cv[i];

                lt[i] = b_mn.query(s - val);

                b_mn.update(
                    s - val + 1,
                    val
                );
            }


            // ---------------------------------
            // Calculate rt
            // ---------------------------------

            for (int i = m + 1; i <= r; i++) {

                int val = cv[i];

                rt[i] = b_mx.query(val - 1);

                b_mx.update(val, val);
            }


            // ---------------------------------
            // Left points
            // ---------------------------------

            vector<pair<int,int>> lpts;

            for (int i = l; i <= m; i++) {
                lpts.push_back({
                    cv[i],
                    lt[i]
                });
            }

            sort(lpts.begin(), lpts.end());


            // ---------------------------------
            // Right queries
            // ---------------------------------

            vector<tuple<int,int,int>> rqry;

            for (int i = m + 1; i <= r; i++) {

                rqry.push_back({
                    cv[i] - 1,
                    cv[i],
                    1
                });
            }

            for (int i = m + 1; i <= r; i++) {

                rqry.push_back({
                    rt[i] - 1,
                    cv[i],
                    -1
                });
            }

            sort(rqry.begin(), rqry.end());


            // ---------------------------------
            // Offline BIT_SUM queries
            // ---------------------------------

            int p = 0;

            for (auto &[qx, qy, sign] : rqry) {

                while (
                    p < (int)lpts.size() &&
                    lpts[p].first <= qx
                ) {

                    int px = lpts[p].first;
                    int py = lpts[p].second;

                    b_sm.update(
                        s - py + 1,
                        1
                    );

                    p++;
                }

                ans +=
                    1LL * sign *
                    b_sm.query(s - qy + 1);
            }


            // ---------------------------------
            // Clear BIT_MIN
            // ---------------------------------

            for (int i = m; i >= l; i--) {

                int val = cv[i];

                b_mn.clear(
                    s - val + 1
                );
            }


            // ---------------------------------
            // Clear BIT_MAX
            // ---------------------------------

            for (int i = m + 1; i <= r; i++) {

                int val = cv[i];

                b_mx.clear(val);
            }


            // ---------------------------------
            // Clear BIT_SUM
            // ---------------------------------

            for (int i = 0; i < p; i++) {

                int py = lpts[i].second;

                b_sm.update(
                    s - py + 1,
                    -1
                );
            }
        };


        cdq(0, n - 1);

        return ans;
    }
};