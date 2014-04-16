/*
Validate Binary Search Tree

Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.

*/
/**
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
    bool isValidBST(TreeNode *root) {
        isValidBSTRe(root,INT_MIN,INT_MAX);
    }
    bool isValidBSTRe(TreeNode *node,int lower,int upper){
        if(!node) return true;
        if(node->val<=lower||node->val>=upper) return false;
        return isValidBSTRe(node->left,lower,node->val)&&isValidBSTRe(node->right,node->val,upper);
    }
};
