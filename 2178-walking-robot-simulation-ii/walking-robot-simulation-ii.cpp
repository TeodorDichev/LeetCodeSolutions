class Robot {
public:
    // solved it with simulation (almost) then read some comment about modular arithmetic
    int W, H, P;
    int pos = 0;
    bool hasMoved = false;

    Robot(int width, int height) {
        W = width - 1;
        H = height - 1;
        P = 2 * (W + H);
    }
    
    void step(int num) {
        hasMoved = true;
        pos = (pos + num) % P;
    }
    
    vector<int> getPos() {
        if(pos <= W) return {pos, 0};
        if(pos <= W + H) return {W, pos - W};
        if(pos <= 2 * W + H) return {W - (pos - (W + H)), H};
        return {0, H - (pos - (2 * W + H))};
    }
    
    string getDir() {
        if(! hasMoved) return "East";
        if(pos == 0) return "South";
        if(pos <= W) return "East";
        if(pos <= W + H) return "North";
        if(pos <= 2 * W + H) return "West";
        return "South";
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */