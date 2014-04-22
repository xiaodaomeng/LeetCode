/**
Binary Tree Maximum Path Sum 
 Given a binary tree, find the maximum path sum.

The path may start and end at any node in the tree.

For example:
Given the below binary tree,

       1
      / \
     2   3
Return 6.

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
    //time O(n), space O(logn), look for left/right subtree path with max sum, add them together
    int maxPathSum(TreeNode *root) {
        int res=INT_MIN;
        maxPathSumRe(root,res);
        return res;
    }
    int maxPathSumRe(TreeNode *root, int &res){
        if(!root) return 0;
        int l=maxPathSumRe(root->left,res);
        int r=maxPathSumRe(root->right,res);
        int sum=max(root->val,max(l,r)+root->val);
        res=max(sum,res);
        res=max(res,l+r+root->val);
        return sum;
    }
};
