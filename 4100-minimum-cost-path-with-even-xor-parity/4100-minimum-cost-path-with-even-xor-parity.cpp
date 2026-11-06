

class Solution {
public:
    using ll = long long;

    const ll INF = (1LL << 60);

    ll ans = INF;

    vector<vector<pair<int, int>>> adj;
    vector<int> parity;

    array<ll, 2> dfs(int u, int parent) {

        // best[p] = minimum cost of a path
        // starting at u with XOR parity p,
        // using only already processed child subtrees.

        array<ll, 2> best = {INF, INF};

        // Path containing only u.
        best[parity[u]] = 0;

        for (auto [v, wt] : adj[u]) {

            if (v == parent) continue;

            // Get DP of child.
            auto child = dfs(v, u);

            for (int q = 0; q < 2; q++) {

                if (child[q] == INF) continue;

                // Extend child path to u.
                int newParity = parity[u] ^ q;

                ll newCost = child[q] + wt;

                // Required parity from another branch.
                int requiredParity = newParity ^ parity[u];

                // Combine with a previously processed branch.
                if (best[requiredParity] != INF) {

                    ans = min(ans,
                              newCost + best[requiredParity]);
                }

            }

            // Insert current child's paths into best.
            for (int q = 0; q < 2; q++) {

                if (child[q] == INF) continue;

                int newParity = parity[u] ^ q;

                ll newCost = child[q] + wt;

                best[newParity] = min(best[newParity], newCost);
            }
        }

        return best;
    }

  int minActivationCost(vector<vector<int>>& edges, vector<int>& values) { 

        int n = values.size();

        adj.assign(n, {});
        parity.resize(n);

        ans = INF;

        // Build tree.
        for (auto &e : edges) {

            int u = e[0];
            int v = e[1];
            int w = e[2];

            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        // Convert values into parity of set bits.
        for (int i = 0; i < n; i++) {
            parity[i] = __builtin_popcount(
                (unsigned int)values[i]
            ) % 2;
        }

        dfs(0, -1);

        return ans == INF ? -1 : ans;
    }
};
