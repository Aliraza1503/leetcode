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
    int val =0;
    void solve(TreeNode* root,long long sum,long long target){
          if(!root) return ;
        sum+=root->val;
        if(sum==target){
            val++;
        }
        solve(root->left,sum,target);
        solve(root->right,sum,target);
        return ;

    }
    int pathSum(TreeNode* root, long long targetSum) {
        if(!root) return 0;
        solve(root,0,targetSum);
        pathSum(root->left,targetSum);
        pathSum(root->right,targetSum);
        return val;
    }
};