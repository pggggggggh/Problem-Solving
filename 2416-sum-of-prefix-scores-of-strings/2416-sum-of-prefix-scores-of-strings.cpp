class Solution {
private:
struct Node {
    Node* childs[26];
    int numChilds;
    Node() {
        numChilds = 0;
        for (int i=0;i<26;i++) childs[i] = nullptr;
    }
};
Node* root;

public:
    Solution() {
        root = new Node();
    }

    vector<int> sumPrefixScores(vector<string>& words) {
        for (string& word:words) {
            Node* cur = root;
            for (char& c:word) {
                if (cur->childs[c-'a'] == nullptr) {
                    cur->childs[c-'a'] = new Node();
                }
                cur = cur->childs[c-'a'];
                cur->numChilds++;
            }
        }
        vector<int> res;
        for (string& word:words) {
            Node* cur = root;
            int curCnt = 0;
            for (char &c:word) {
                cur = cur->childs[c-'a'];
                curCnt += cur->numChilds;
            }
            res.push_back(curCnt);
        }
        return res;
    }
};