/**
Balanced Binary Tree 
Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

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
    //time O(n),space O(logn)
    bool isBalanced(TreeNode *root) {
        int height=0;
        return isBalancedRe(root,height);
    }
    bool isBalancedRe(TreeNode *node,int &height){
        if(!node) return true;
        int lh=0,rh=0;
        if(!isBalancedRe(node->left,lh)) return false;
        if(!isBalancedRe(node->right,rh)) return false;
        if(abs(lh-rh)>1) return false;
        height=1+max(lh,rh);
        return true;
    }
};
