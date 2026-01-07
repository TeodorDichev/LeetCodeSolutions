#include <vector>
#include <numeric>

using namespace std;

class Solution {
    struct UnionFind {
        vector<int> parent; // Changed from 'parents' to 'parent' vector
        vector<int> size;
        int components;

        UnionFind(int n) : parent(n), size(n, 1), components(n) {
            // Initialize each node as its own parent
            iota(parent.begin(), parent.end(), 0);
        }

        int find(int node) {
            if (parent[node] == node) {
                return node;
            }
            // Path compression
            return parent[node] = find(parent[node]);
        }

        void unite(int a, int b) {
            int rootA = find(a);
            int rootB = find(b);

            if (rootA != rootB) {
                // Union by size: attach the smaller tree to the larger tree
                if (size[rootA] < size[rootB]) {
                    swap(rootA, rootB);
                }
                parent[rootB] = rootA;
                size[rootA] += size[rootB];
                components--;
            }
        }
    };

public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        // n edges in a tree + 1 extra edge means there are n nodes. 
        // We use n+1 to handle 1-based indexing comfortably.
        UnionFind uf(n + 1);

        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];

            // If they already share a root, this edge creates a cycle
            if (uf.find(u) == uf.find(v)) {
                return edge;
            }
            uf.unite(u, v);
        }

        return {};
    }
};