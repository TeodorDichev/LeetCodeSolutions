class SmallestInfiniteSet {
    int current;
    set<int> addedBack;

public:
    SmallestInfiniteSet() : current(1) {}

    int popSmallest() {
        if (!addedBack.empty()) {
            int x = *addedBack.begin();
            addedBack.erase(addedBack.begin());
            return x;
        }
        return current++;
    }

    void addBack(int num) {
        if (num < current) {
            addedBack.insert(num);
        }
    }
};
