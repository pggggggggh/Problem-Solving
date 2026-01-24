class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;
        for (int& num:nums) pq.push(num);
        int repeat = k-1;
        while (repeat--) pq.pop();
        return pq.top();
    }
};