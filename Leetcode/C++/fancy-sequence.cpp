class Fancy {
private:
    vector<int> seq;
public:
    Fancy() {
        this->seq.clear();
    }
    
    void append(int val) {
        this->seq.push_back(val);
    }
    
    void addAll(int inc) {
        for (auto &x : this->seq)
            x = (x + inc) % 1000000007;
    }
    
    void multAll(int m) {
        for (auto &x : this->seq)
            x = 1ll * x * m % 1000000007;
    }
    
    int getIndex(int idx) {
        int size = this->seq.size();
        if (idx >= size) return -1;
        return (this->seq[idx]);
    }
};

/**
 * Your Fancy object will be instantiated and called as such:
 * Fancy* obj = new Fancy();
 * obj->append(val);
 * obj->addAll(inc);
 * obj->multAll(m);
 * int param_4 = obj->getIndex(idx);
 */