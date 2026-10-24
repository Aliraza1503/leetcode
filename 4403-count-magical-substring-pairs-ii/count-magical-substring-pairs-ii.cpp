class Solution {
public:
    long long countMagicalPairs(string s) {
        int n = s.size();
        // R[a][c] = number of k >= a such that distinct(s[a..k]) == c
        vector<array<int, 27>> R(n + 1);
        for (auto &r : R) r.fill(0);

        vector<int> order;          // letters ordered by nearest first occurrence
        int pos[26];

        for (int a = n - 1; a >= 0; a--) {
            int ch = s[a] - 'a';
            auto it = find(order.begin(), order.end(), ch);
            if (it != order.end()) order.erase(it);
            order.insert(order.begin(), ch);
            pos[ch] = a;
            int m = order.size();
            for (int t = 0; t < m; t++) {
                int cur = pos[order[t]];
                int nxt = (t + 1 < m) ? pos[order[t + 1]] : n;
                R[a][t + 1] = nxt - cur;   // k in [cur, nxt) -> distinct = t+1
            }
        }

        long long ans = 0;
        order.clear();
        // order: letters by most recent last occurrence
        for (int j = 0; j + 1 < n; j++) {
            int ch = s[j] - 'a';
            auto it = find(order.begin(), order.end(), ch);
            if (it != order.end()) order.erase(it);
            order.insert(order.begin(), ch);
            pos[ch] = j;
            int m = order.size();
            for (int t = 0; t < m; t++) {
                int cur = pos[order[t]];
                int nxt = (t + 1 < m) ? pos[order[t + 1]] : -1;
                long long cntL = cur - nxt;  // i in (nxt, cur] -> distinct = t+1
                ans += cntL * R[j + 1][t + 1];
            }
        }
        return ans;
    }
};