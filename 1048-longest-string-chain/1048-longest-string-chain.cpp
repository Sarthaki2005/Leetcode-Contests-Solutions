class Solution {
public:
    bool check(string& s1, string& s2) {
        if (s1.size() != s2.size() - 1) {
            return false;
        }
        int n = s1.size();
        int m = s2.size();
        int i = 0, j = 0;
        while (j < m) {
            if (s1[i] == s2[j]) {
                i++;
                j++;
            } else {
                j++;
            }
        }
        return i == n;
    }
    int f(int idx, int prev, vector<string>& words,vector<vector<int>> &dp) {
        if (idx >= words.size()) {
            return 0;
        }
        if(prev!=-1 && dp[idx][prev]!=-1) return dp[idx][prev];
        int take = 0;
        if (prev == -1 || check(words[prev], words[idx])) {
            take = 1 + f(idx + 1, idx, words,dp);
        }
        int not_take = f(idx + 1, prev, words,dp);
        if(prev==-1) return max(take,not_take);
        return dp[idx][prev]=max(take, not_take);
    }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(),
             [](const string& s1, const string& s2) {
                 return s1.size() < s2.size();
             });
             int n=words.size();
             vector<vector<int>> dp(n,vector<int>(n,-1));
        return f(0, -1, words,dp);
    }
};