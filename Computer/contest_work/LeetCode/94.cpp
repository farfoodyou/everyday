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
public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode> s;
        vector<int> ans;
        TreeNode* t = root;
        while(t || !s.empty()){
            while(t){                //遍历到最左边的叶结点
                s.push(*t);
                t = t->left;
            }
            if(!s.empty()){
                ans.push_back(s.top().val);
                t = s.top().right;
                s.pop();
            }
        }
        return ans;
    }
};

// 用栈模拟递归调用

