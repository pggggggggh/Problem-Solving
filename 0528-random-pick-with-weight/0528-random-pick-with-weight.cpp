class Solution {
private:
    vector<int> points;
    random_device rd;
    mt19937 gen;
    uniform_int_distribution<int> dis;
    
public:
    Solution(vector<int>& w) {
        int curPosition = 0;
        for (int &x: w) {
            points.push_back(curPosition);
            curPosition += x;
        }
        gen = mt19937(rd());
        dis = uniform_int_distribution<int>(0,curPosition-1);
    }
    
    int pickIndex() {
        int x = dis(gen);
        int idx = upper_bound(points.begin(),points.end(),x)-points.begin()-1;
        return idx;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */