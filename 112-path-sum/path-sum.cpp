/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool solve(TreeNode* root,int t){
        if(!root->left&&!root->right){
            return t==root->val;
        }
        bool check = false;
        if(root->left){
            check = check||solve(root->left,t-root->val);
        }
        if(root->right){
            check = check||solve(root->right,t-root->val);
        }
        return check;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root) return false;
        return solve(root,targetSum);
    }
};