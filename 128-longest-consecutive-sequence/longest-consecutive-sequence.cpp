class Solution {
public:
    class UnionFind {
    public:
        unordered_map<int, int> parent, size;

        int find(int x) {
            if (parent[x] != x) parent[x] = find(parent[x]);
            return parent[x];
        }

        void unite(int x, int y) {
            int px = find(x), py = find(y);
            if (px == py) return;
            if (size[px] < size[py]) swap(px, py);
            parent[py] = px;
            size[px] += size[py];
        }

        void add(int x) {
            if (!parent.count(x)) {
                parent[x] = x;
                size[x] = 1;
            }
        }
    };

    int longestConsecutive(vector<int>& nums) {
        UnionFind uf;
        for (int x : nums) uf.add(x);

        for (int x : nums) {
            if (uf.parent.count(x + 1)) uf.unite(x, x + 1);
        }

        int maxLen = 0;
        for (auto& [_, sz] : uf.size) maxLen = max(maxLen, sz);
        return maxLen;
    }
    // intuitive approach 
    // int longestConsecutive(vector<int>& nums) {
    // unordered_set<int> s(nums.begin(), nums.end());
    // int maxLen = 0;

    // for (int num : nums) {
    //     if (!s.count(num - 1)) {
    //         int curr = num;
    //         int len = 1;
    //         while (s.count(curr + 1)) {
    //             ++curr;
    //             ++len;
    //         }
    //         maxLen = max(maxLen, len);
    //     }
    // }

    // return maxLen;
    // }
};