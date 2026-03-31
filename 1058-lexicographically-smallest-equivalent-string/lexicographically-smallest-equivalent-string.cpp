class Solution {
    struct UnionFind {
        vector<int> depth;
        vector<int> parents;

        UnionFind() {
            depth.resize(26);
            parents.resize(26);
            for (int i = 0; i < 26; i++) {
                parents[i] = i;
            }
        }

        int find(int node) {
            int parent = parents[node];
            if (parent == node) return parent;
            return parents[node] = find(parent);
        }

        bool join(int node1, int node2) {
            int root1 = find(node1);
            int root2 = find(node2);

            if (root1 == root2) return false;
            if (depth[root1] < depth[root2]) swap(root1, root2);

            if (root1 < root2) {
                parents[root2] = root1;
                if (depth[root1] == depth[root2]) depth[root1]++;
            } else {
                parents[root1] = root2;
                if (depth[root2] == depth[root1]) depth[root2]++;
            }
            
            return true;
        }
    };

public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        UnionFind uf;

        int n = s1.size();
        for (int i = 0; i < n; i++) {
            uf.join(s1[i] - 'a', s2[i] - 'a');
        }

        string result;
        for (int i = 0; i < baseStr.size(); i++) {
            int ch = uf.find(baseStr[i] - 'a');
            result += ('a' + ch);
        }

        return result;
    }
};