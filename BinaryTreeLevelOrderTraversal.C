/**
 Binary Tree Level Order Traversal 
Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree {3,9,20,#,#,15,7},
    3
   / \
  9  20
    /  \
   15   7
return its level order traversal as:
[
  [3],
  [9,20],
  [15,7]
]
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    //iterative: time O(n), space O(n)
    vector<vector<int> > levelOrder(TreeNode *root) {
        vector<vector<int>> res;
        if(!root) return res;
        queue<TreeNode *> q;
        q.push(root);
        q.push(NULL);
        vector<int> level;
        while(!q.empty()){
            TreeNode* node=q.front();
            q.pop();
            if(!node){
                res.push_back(level);
                level.clear();
                if(q.empty()) break;
                q.push(NULL);
            }
            else{
                level.push_back(node->val);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
        }
        return res;
    }
};
