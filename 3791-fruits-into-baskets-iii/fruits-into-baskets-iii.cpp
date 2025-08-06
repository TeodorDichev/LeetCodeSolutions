class Segtree {
    int allocate_size;
    vector<int> t;

public:
    Segtree(const vector<int>& arr) {
        int n = arr.size();
        allocate_size = 1;
        while (allocate_size < n) allocate_size <<= 1;

        t.assign(allocate_size * 2, 0);
        for (int i = 0; i < n; ++i)
            t[allocate_size + i] = arr[i];

        for (int i = allocate_size - 1; i > 0; --i)
            t[i] = max(t[i << 1], t[(i << 1) | 1]);
    }

    void update_to_zero(int x) {
        x += allocate_size;
        t[x] = 0;
        x >>= 1;
        while (x > 0) {
            t[x] = max(t[x << 1], t[(x << 1) | 1]);
            x >>= 1;
        }
    }

    int query(int x) {
        int idx = 1;
        while (idx < allocate_size) {
            if (t[idx << 1] >= x)
                idx = idx << 1;
            else if (t[(idx << 1) | 1] >= x)
                idx = (idx << 1) | 1;
            else
                return -1;
        }
        return (t[idx] >= x) ? (idx - allocate_size) : -1;
    }
};

class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        Segtree s(baskets);
        int res = 0;

        for (int fruit : fruits) {
            int basket = s.query(fruit);
            if (basket == -1)
                ++res;
            else
                s.update_to_zero(basket);
        }

        return res;
    }
};