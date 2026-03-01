/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    map<int,vector<int>> adj;
    vector<int> res;
    int k;

    void recur(TreeNode* u) {
        if (u->left) {
            adj[u->val].push_back(u->left->val);
            adj[u->left->val].push_back(u->val);
            recur(u->left);
        }
        if (u->right) {
            adj[u->val].push_back(u->right->val);
            adj[u->right->val].push_back(u->val);
            recur(u->right);
        }
    }

    void go(int u, int p, int depth) {
        if (depth == k) {
            res.push_back(u);
            return;
        }
        for (auto &v:adj[u]) {
            if (v==p) continue;
            go(v,u,depth+1);
        }
    }

public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        this->k = k;
        recur(root);
        go(target->val,-1,0);
        return res;
    }
};